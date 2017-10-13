#ifndef FASTQ_SEQUENCE_HH
#define FASTQ_SEQUENCE_HH

#include <string>
#include <iostream>

struct FastqEntry
{
    std::string id;
    std::string seq;
    std::string quals;

    static bool increasing_size_comp(const FastqEntry& fastq_entry1, const FastqEntry& fastq_entry2);
    static bool decreasing_size_comp(const FastqEntry& fastq_entry1, const FastqEntry& fastq_entry2);
};

inline bool FastqEntry::increasing_size_comp(const FastqEntry& fastq_entry1, const FastqEntry& fastq_entry2)
{
    return fastq_entry1.seq.size() < fastq_entry2.seq.size();
}

inline bool FastqEntry::decreasing_size_comp(const FastqEntry& fastq_entry1, const FastqEntry& fastq_entry2)
{
    return fastq_entry1.seq.size() > fastq_entry2.seq.size();
}

std::ostream& operator<<(std::ostream& os, const FastqEntry& fastq_entry);

#endif //FASTQ_SEQUENCE_HH
