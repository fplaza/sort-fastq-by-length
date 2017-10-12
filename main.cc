#include "Parameters.hh"
#include <iostream>
#include <cstdlib>
#include <parallel/algorithm>
#include "FastqMultiReader.hh"
#include "FastqPrinter.hh"

bool fastq_length_comparator(const FastqEntry& fastq_entry1, const FastqEntry& fastq_entry2)
{
    return fastq_entry1.seq.size() > fastq_entry2.seq.size();
}

int main(int argc, char *argv[])
{
    try
    {
        const Parameters& parameters = Parameters::parse(argc, argv);
        std::cout << parameters << std::endl;

        FastqMultiReader fastq_multi_reader(parameters.fastq_files);
        std::vector<FastqEntry> all_fastq_entries;
        std::vector<FastqEntry> chunk_fastq_entries;

        std::cout << "Loading reads..." << std::endl;
        while (fastq_multi_reader.next_chunk(chunk_fastq_entries))
        {
            all_fastq_entries.insert(all_fastq_entries.end(), chunk_fastq_entries.begin(), chunk_fastq_entries.end());
        }
        std::cout << all_fastq_entries.size() << " reads loaded.\n" << std::endl;

        std::cout << "Sorting reads by length..." << std::endl;
        __gnu_parallel::sort(all_fastq_entries.begin(), all_fastq_entries.end(),
                fastq_length_comparator);
        std::cout << "Done.\n" << std::endl;

        std::cout << "Writing sorted reads..." << std::endl;
        FastqPrinter fastq_printer(parameters.output_file);
        fastq_printer.print_fastq_entries(all_fastq_entries);
        std::cout << "Done." << std::endl;

        std::exit(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(-1);
    }
}
