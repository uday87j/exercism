#ifndef RNA_TRANSCRIPTION_H_
#define RNA_TRANSCRIPTION_H_

#include <string>
#include <algorithm>
#include <iterator>

namespace transcription    {

    extern void to_neutral(std::string& dna);

    extern void to_final(std::string& dna);

    extern char to_rna(const char c);

    extern std::string to_rna(const std::string& dna);

}
#endif
