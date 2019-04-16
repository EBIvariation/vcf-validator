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
    virtual void process(FastaIndexer * fasta_indexer, std::istream & input) = 0;
    virtual ~FastaIndexerState(){}
};

class NewContigState : public FastaIndexerState {
public:
    void process(FastaIndexer * fasta_indexer, std::istream & input);
};

class ContigNameState : public FastaIndexerState {
public:
    void process(FastaIndexer * fasta_indexer, std::istream & input);
};

class ContigDescriptionState : public FastaIndexerState {
public:
    void process(FastaIndexer * fasta_indexer, std::istream & input);
};

class ContigSequenceState : public FastaIndexerState {
public:
    void process(FastaIndexer * fasta_indexer, std::istream & input);
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
    for (ContigIndex contig_index : fasta_index) {
        output << contig_index.name << "\t"
            << contig_index.seq_length << "\t"
            << contig_index.seq_offset << "\t"
            << contig_index.line_length << "\t"
            << contig_index.line_bytes << "\n";
    }

    return output;
}

void
FastaIndexer::set_state(FastaIndexerState *state)
{
    current_state.reset(state);
}

void
NewContigState::process(FastaIndexer *fasta_indexer, std::istream & input)
{
    fasta_indexer->fasta_index.push_back({"", 0, 0, 0, 0});
    fasta_indexer->set_state(new ContigNameState());
}

void
ContigNameState::process(FastaIndexer *fasta_indexer, std::istream & input)
{
    char c;
    ContigIndex & contig_index = fasta_indexer->fasta_index[fasta_indexer->fasta_index.size()-1];
    while (input && input.get(c)) {
        if (c == ' ') {
            fasta_indexer->set_state(new ContigDescriptionState());
            return;
        }
        else if (c == '\n') {
            fasta_indexer->set_state(new ContigSequenceState());
            return;
        }
        else {
            contig_index.name.push_back(c);
        }
    }

    fasta_indexer->set_state(nullptr);
}

void
ContigDescriptionState::process(FastaIndexer *fasta_indexer, std::istream & input)
{
    char c;
    while (input && input.get(c)) {
        if (c == '\n') {
            fasta_indexer->set_state(new ContigSequenceState());
            return;
        }
    }

    fasta_indexer->set_state(nullptr);
}

void
ContigSequenceState::process(FastaIndexer *fasta_indexer, std::istream & input)
{
    ContigIndex & contig_index = fasta_indexer->fasta_index[fasta_indexer->fasta_index.size()-1];
    contig_index.seq_offset = input.tellg();

    uint64_t seq_length = 0;
    uint32_t line_length = 0;
    uint32_t line_bytes = 0;
    char c;
    bool is_first_line = true;
    while (input && input.get(c)) {
        if (c == '\n') {
            if (is_first_line) {
                ++line_bytes;
                contig_index.line_length = line_length;
                contig_index.line_bytes = line_bytes;
                is_first_line = false;
            }
        }
        else if (c == '>') {
            contig_index.seq_length = seq_length;
            fasta_indexer->set_state(new NewContigState());
            return;
        }
        else {
            if (is_first_line) {
                ++line_length;
                ++line_bytes;
            }
            ++seq_length;
        }
    }

    contig_index.seq_length = seq_length;
    fasta_indexer->set_state(nullptr);
}

std::ostream &
ebi::vcf::faidx::index_fasta(std::istream & input, std::ostream & output)
{
    FastaIndexer fasta_indexer;
    fasta_indexer.index(input, output);
    return output;
}
