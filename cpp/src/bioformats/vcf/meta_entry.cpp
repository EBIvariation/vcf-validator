#include <iostream>
#include "file_structure.hpp"
#include "meta_entry_visitor.hpp"

namespace opencb
{
  namespace vcf
  {
  
    MetaEntry::MetaEntry(std::string const & id,
                         std::shared_ptr<Source> const & source)
    : id{id}, structure{Structure::NoValue}, source{source}
    {
        
    }
  
    MetaEntry::MetaEntry(std::string const & id, 
                         std::string const & plain_value,
                         std::shared_ptr<Source> const & source)
    : id{id}, structure{Structure::PlainValue}, value{plain_value}, source{source}
    {
        check_value();
    }
        
    MetaEntry::MetaEntry(std::string const & id,
                         std::map<std::string, std::string> const & key_values,
                         std::shared_ptr<Source> const & source)
    : id{id}, structure{Structure::KeyValue}, value{key_values}, source{source}
    {
        check_value();
    }
    
    bool MetaEntry::operator==(MetaEntry const & other) const
    {
        return id == other.id &&
               value == other.value;
    }

    bool MetaEntry::operator!=(MetaEntry const & other) const
    {
        return !(*this == other);
    }
    
    void MetaEntry::check_value()
    {
        MetaEntryVisitor visitor = MetaEntryVisitor { *this }; 
        boost::apply_visitor(visitor, value);
    }
     
    
    MetaEntryVisitor::MetaEntryVisitor(MetaEntry const & entry)
    : entry{entry}
    {
        
    }
       
    void MetaEntryVisitor::operator()(std::string & value) const
    {
        if (find_if(value.begin(), value.end(), [](char c) { return c == '\n'; }) != value.end()) {
            throw std::invalid_argument("Metadata value contains a line break");
        }
    }
    
    void MetaEntryVisitor::operator()(std::map<std::string, std::string> & value) const
    {
        auto & id = entry.id;
        if (id == "ALT") { 
            check_alt(value);
        } else if (id == "assembly") {
            // TODO May check URL correctness (regexp?)
        } else if (id == "contig") {
            check_contig(value);
        } else if (id == "FILTER") {
            check_filter(value);
        } else if (id == "FORMAT") {
            check_format(value);
        } else if (id == "INFO") {
            check_info(value);
        } else if (id == "PEDIGREE") {
            // Nothing to check
        } else if (id == "pedigreeDB") {
            // Nothing to check
        } else if (id == "SAMPLE") {
            check_sample(value);
        }
    }
    
    void MetaEntryVisitor::check_alt(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("ALT metadata does not contain a field called 'ID'");
        }
        if (value.count("Description") == 0) {
            throw std::invalid_argument("ALT metadata does not contain a field called 'Description'");
        }
        
        // Check ID prefix is "DEL" | "INS" | "DUP" | "INV" | "CNV"
        auto & id_field = value["ID"];
        size_t pos = id_field.find(':');
        // If a colon was not found, check whole string
        // Otherwise, check substring before colon
        std::string prefix = (pos == std::string::npos) ? id_field : id_field.substr(0, pos);
        if (prefix != "DEL" && 
            prefix != "INS" && 
            prefix != "DUP" && 
            prefix != "INV" && 
            prefix != "CNV") {
            throw std::invalid_argument("ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        }
    }
    
    void MetaEntryVisitor::check_contig(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("contig metadata does not contain a field called 'ID'");
        }
    }
    
    void MetaEntryVisitor::check_filter(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("FILTER metadata does not contain a field called 'ID'");
        }
        if (value.count("Description") == 0) {
            throw std::invalid_argument("FILTER metadata does not contain a field called 'Description'");
        }
    }
    
    void MetaEntryVisitor::check_format(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID, Number, Type and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("FORMAT metadata does not contain a field called 'ID'");
        }
        if (value.count("Number") == 0) {
            throw std::invalid_argument("FORMAT metadata does not contain a field called 'Number'");
        }
        if (value.count("Type") == 0) {
            throw std::invalid_argument("FORMAT metadata does not contain a field called 'Type'");
        }
        if (value.count("Description") == 0) {
            throw std::invalid_argument("FORMAT metadata does not contain a field called 'Description'");
        }
        
        // Check FORMAT Number
        auto & number_field = value["Number"];
        if (find_if(number_field.begin(), number_field.end(), [](char c) { return !isdigit(c); }) != number_field.end() &&
            value["Number"] != "A" &&
            value["Number"] != "R" &&
            value["Number"] != "G" &&
            value["Number"] != ".") {
            throw std::invalid_argument("FORMAT metadata Number is not a number, A, R, G or dot");
        }

        // Check FORMAT Type
        if (value["Type"] != "Integer" &&
            value["Type"] != "Float" &&
            value["Type"] != "Character" &&
            value["Type"] != "String") {
            throw std::invalid_argument("FORMAT metadata Type is not a Integer, Float, Character or String");
        }
    }
    
    void MetaEntryVisitor::check_info(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID, Number, Type and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("INFO metadata does not contain a field called 'ID'");
        }
        if (value.count("Number") == 0) {
            throw std::invalid_argument("INFO metadata does not contain a field called 'Number'");
        }
        if (value.count("Type") == 0) {
            throw std::invalid_argument("INFO metadata does not contain a field called 'Type'");
        }
        if (value.count("Description") == 0) {
            throw std::invalid_argument("INFO metadata does not contain a field called 'Description'");
        }
        
        // Check INFO Number
        auto & number_field = value["Number"];
        if (find_if(number_field.begin(), number_field.end(), [](char c) { return !isdigit(c); }) != number_field.end() &&
            value["Number"] != "A" &&
            value["Number"] != "R" &&
            value["Number"] != "G" &&
            value["Number"] != ".") {
            throw std::invalid_argument("INFO metadata Number is not a number, A, R, G or dot");
        }

        // Check INFO Type
        if (value["Type"] != "Integer" &&
            value["Type"] != "Float" &&
            value["Type"] != "Flag" &&
            value["Type"] != "Character" &&
            value["Type"] != "String") {
            throw std::invalid_argument("INFO metadata Type is not a Integer, Float, Flag, Character or String");
        }
    }
    
    void MetaEntryVisitor::check_sample(std::map<std::string, std::string> & value) const
    {
        // It must contain an ID
        if (value.count("ID") == 0) {
            throw std::invalid_argument("SAMPLE metadata does not contain a field called 'ID'");
        }
    }
    
  }
}