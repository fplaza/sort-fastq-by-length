#ifndef PARAMETERS_HH
#define PARAMETERS_HH
 
#include <vector>
#include <string>
#include <iostream>

struct Parameters
{
    std::vector<std::string> fastq_files;
    std::string output_file;
    static Parameters parse(int argc, char* argv[]);
    static void check_file_is_readable(const std::string& filepath);
    static void check_file_is_writable(const std::string& filepath);
};

std::ostream& operator<<(std::ostream& os, const Parameters& parameters);

#endif // PARAMETERS_HH
