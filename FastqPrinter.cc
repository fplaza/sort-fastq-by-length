#include "FastqPrinter.hh"
#include <fstream>

void FastqPrinter::print_fastq_entries(const std::vector<FastqEntry>& fastq_entries)
{
    std::ofstream ofs;
    ofs.open(output_file_.c_str());

    for(std::vector<FastqEntry>::const_iterator fastq_entry = fastq_entries.begin(); fastq_entry < fastq_entries.end(); ++fastq_entry)
    {
        ofs << *fastq_entry;
    }

    ofs.close();
}
