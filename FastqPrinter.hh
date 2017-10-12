#ifndef FASTQ_PRINTER_HH
#define FASTQ_PRINTER_HH

#include <string>
#include <vector>
#include "FastqEntry.hh"

class FastqPrinter
{
    public:
        FastqPrinter(const std::string& output_file);
        void print_fastq_entries(const std::vector<FastqEntry>& fastq_entries);

    private:
        const std::string output_file_;
};


inline FastqPrinter::FastqPrinter(const std::string& output_file)
    : output_file_(output_file)
{};
    
#endif // FASTQ_PRINTER_HH
