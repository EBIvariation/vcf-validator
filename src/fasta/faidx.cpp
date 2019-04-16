/**
 * Copyright 2019 EMBL - European Bioinformatics Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include "fasta/faidx.hpp"

struct ContigIndex {
    std::string name;     // Name of this contig
    uint64_t seq_length;  // Total length of this contig, in bases
    uint64_t seq_offset;  // Offset in the FASTA file of this contig's first base
    uint32_t line_length; // The number of bases in each line
    uint32_t line_bytes;  // The number of bytes in each line, including the newline
};

class FastaIndexerState;

class FastaIndexer {
public:
    std::ostream & index(std::istream & input, std::ostream & output);

private:
    friend class NewContigState;
    friend class ContigNameState;
    friend class ContigDescriptionState;
    friend class ContigSequenceState;

    void set_state(FastaIndexerState* state);

    std::unique_ptr<FastaIndexerState> current_state;
    std::vector<ContigIndex> fasta_index;
};

class FastaIndexerState {
public:
    virtual void process(FastaIndexer * fastaIndexer, std::istream & input) = 0;
    virtual ~FastaIndexerState(){}
};

class NewContigState : public FastaIndexerState {
public:
    void process(FastaIndexer * fastaIndexer, std::istream & input);
};

class ContigNameState : public FastaIndexerState {
public:
    void process(FastaIndexer * fastaIndexer, std::istream & input);
};

class ContigDescriptionState : public FastaIndexerState {
public:
    void process(FastaIndexer * fastaIndexer, std::istream & input);
};

class ContigSequenceState : public FastaIndexerState {
public:
    void process(FastaIndexer * fastaIndexer, std::istream & input);
};

std::ostream &
FastaIndexer::index(std::istream &input, std::ostream &output)
{
    current_state.reset(nullptr);
    fasta_index.clear();

    char c;
    if (input && input.get(c)) {
        if (c == '>') {
            set_state(new NewContigState());
            while (current_state.get()) {
                current_state->process(this, input);
            }
        }
    }

    output.clear();
    for (ContigIndex contigIndex : fasta_index) {
        output << contigIndex.name << "\t"
            << contigIndex.seq_length << "\t"
            << contigIndex.seq_offset << "\t"
            << contigIndex.line_length << "\t"
            << contigIndex.line_bytes << "\n";
    }

    return output;
}

void
FastaIndexer::set_state(FastaIndexerState *state)
{
    current_state.reset(state);
}

void
NewContigState::process(FastaIndexer *fastaIndexer, std::istream & input)
{
    fastaIndexer->fasta_index.push_back({"", 0, 0, 0, 0});
    fastaIndexer->set_state(new ContigNameState());
}

void
ContigNameState::process(FastaIndexer *fastaIndexer, std::istream & input)
{
    char c;
    ContigIndex & contigIndex = fastaIndexer->fasta_index[fastaIndexer->fasta_index.size()-1];
    while (input && input.get(c)) {
        if (c == ' ') {
            fastaIndexer->set_state(new ContigDescriptionState());
            return;
        }
        else if (c == '\n') {
            fastaIndexer->set_state(new ContigSequenceState());
            return;
        }
        else {
            contigIndex.name.push_back(c);
        }
    }

    fastaIndexer->set_state(nullptr);
}

void
ContigDescriptionState::process(FastaIndexer *fastaIndexer, std::istream & input)
{
    char c;
    while (input && input.get(c)) {
        if (c == '\n') {
            fastaIndexer->set_state(new ContigSequenceState());
            return;
        }
    }

    fastaIndexer->set_state(nullptr);
}

void
ContigSequenceState::process(FastaIndexer *fastaIndexer, std::istream & input)
{
    ContigIndex & contigIndex = fastaIndexer->fasta_index[fastaIndexer->fasta_index.size()-1];
    contigIndex.seq_offset = input.tellg();

    uint64_t seq_length = 0;
    uint32_t line_length = 0;
    uint32_t line_bytes = 0;
    char c;
    bool firstLine = true;
    while (input && input.get(c)) {
        if (c == '\n') {
            if (firstLine) {
                ++line_bytes;
                contigIndex.line_length = line_length;
                contigIndex.line_bytes = line_bytes;
                firstLine = false;
            }
        }
        else if (c == '>') {
            contigIndex.seq_length = seq_length;
            fastaIndexer->set_state(new NewContigState());
            return;
        }
        else {
            if (firstLine) {
                ++line_length;
                ++line_bytes;
            }
            ++seq_length;
        }
    }

    contigIndex.seq_length = seq_length;
    fastaIndexer->set_state(nullptr);
}

std::ostream &
ebi::vcf::faidx::index_fasta(std::istream & input, std::ostream & output)
{
    FastaIndexer fastaIndexer;
    fastaIndexer.index(input, output);
    return output;
}
