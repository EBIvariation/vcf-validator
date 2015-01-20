#include "file_structure.hpp"

namespace opencb
{
  namespace vcf
  {
  
    MetaEntry::MetaEntry(std::string const & id)
    : id{id}, structure{Structure::NoValue}
    {
        
    }
  
    MetaEntry::MetaEntry(std::string const & id, 
                         std::string const & plain_value)
    : id{id}, structure{Structure::PlainValue}, value{plain_value}
    {
        check_value();
    }
        
    MetaEntry::MetaEntry(std::string const & id,
                         std::map<std::string, std::string> const & key_values)
    : id{id}, structure{Structure::KeyValue}, value{key_values}
    {
        check_value();
    }
    
    bool MetaEntry::operator==(MetaEntry const & other)
    {
        return id == other.id &&
               value == other.value;
    }

    bool MetaEntry::operator!=(MetaEntry const & other)
    {
        return !(*this == other);
    }
    
    void MetaEntry::check_value()
    {
        if (std::string* plain_value = boost::get<std::string>(&value)) {
            check_plain_value(*plain_value);
        } else if (std::map<std::string, std::string>* key_values 
                = boost::get<std::map<std::string, std::string>>(&value)) {
            check_key_values(*key_values);
        }
    }
    
    void MetaEntry::check_plain_value(std::string value)
    {
        if (find_if(id.begin(), id.end(), [](char c) { return c == '\n'; }) != id.end()) {
            throw std::invalid_argument("Metadata value contains a line break");
        }
    }
    
    void MetaEntry::check_key_values(std::map<std::string, std::string> value)
    {
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
    
    void MetaEntry::check_alt(std::map<std::string, std::string> value)
    {
        // It must contain an ID and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("ALT metadata does not contain a field called 'ID'");
        }
        if (value.count("Description") == 0) {
            throw std::invalid_argument("ALT metadata does not contain a field called 'Description'");
        }
        
        // Check ID prefix is "DEL" | "INS" | "DUP" | "INV" | "CNV"
        size_t pos = id.find(':');
        // If a colon was not found, check whole string
        // Otherwise, check substring before colon
        std::string prefix = (pos == std::string::npos) ? id : id.substr(0, pos);
        if (prefix != "DEL" && 
            prefix != "INS" && 
            prefix != "DUP" && 
            prefix != "INV" && 
            prefix != "CNV") {
            throw std::invalid_argument("ALT metadata ID does not begin with DEL/INS/DUP/INV/CNV");
        }
    }
    
    void MetaEntry::check_contig(std::map<std::string, std::string> value)
    {
        // It must contain an ID and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("contig metadata does not contain a field called 'ID'");
        }
    }
    
    void MetaEntry::check_filter(std::map<std::string, std::string> value)
    {
        // It must contain an ID and Description
        if (value.count("ID") == 0) {
            throw std::invalid_argument("FILTER metadata does not contain a field called 'ID'");
        }
        if (value.count("Description") == 0) {
            throw std::invalid_argument("FILTER metadata does not contain a field called 'Description'");
        }
    }
    
    void MetaEntry::check_format(std::map<std::string, std::string> value)
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
        if (find_if(id.begin(), id.end(), [](char c) { return !isdigit(c); }) != id.end() &&
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
    
    void MetaEntry::check_info(std::map<std::string, std::string> value)
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
        if (find_if(id.begin(), id.end(), [](char c) { return !isdigit(c); }) != id.end() &&
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
    
    void MetaEntry::check_sample(std::map<std::string, std::string> value)
    {
        // It must contain an ID
        if (value.count("ID") == 0) {
            throw std::invalid_argument("SAMPLE metadata does not contain a field called 'ID'");
        }
    }
    
  }
}