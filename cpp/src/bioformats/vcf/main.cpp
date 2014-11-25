/* 
 * File:   main.cpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 *
 * Created on 19 November 2014, 15:54
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int run_vcf_parser(const string & input_text);

/*
 * 
 */
int main(int argc, char** argv)
{
    if (argc < 2) {
        cerr << "Please provide an input VCF file" << endl;
        return 1;
    }
    
    ifstream input {argv[1]};
    
    // Read header
    stringstream buffer_text;
    for(string line; getline(input, line) && line[0] == '#'; )
    {
        buffer_text << line << endl;
    }
    cout << buffer_text.str() << endl;
    cout << "Result: " << run_vcf_parser(buffer_text.str()) << endl;
    
    // Read body
    buffer_text.str(string{});
    for(string line; getline(input, line); )
    {
        buffer_text << line << endl;
    }
    cout << buffer_text.str() << endl;
    cout << "Result: " << run_vcf_parser(buffer_text.str()) << endl;
    
    return 0;
}

