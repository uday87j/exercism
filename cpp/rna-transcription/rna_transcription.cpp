#include "rna_transcription.h"

#include <algorithm>
#include <iterator>

namespace transcription {

    void to_neutral(std::string& dna)   {
        std::for_each(std::begin(dna), std::end(dna), [](char& c)  {
                if(c == 'G')    c = 'W';
                else if(c == 'C')   c = 'X';
                else if(c == 'T')   c = 'Y';
                else if(c == 'A')   c = 'Z';
                });
    }

    void to_final(std::string& dna)   {
        std::for_each(std::begin(dna), std::end(dna), [](char& c)  {
                if(c == 'W')    c = 'C';
                else if(c == 'X')   c = 'G';
                else if(c == 'Y')   c = 'A';
                else if(c == 'Z')   c = 'U';
                });
    }

    char to_rna(const char c)    {
        char rc = c;
        if(c == 'G')    rc = 'C';
        else if(c == 'C')   rc = 'G';
        else if(c == 'T')   rc = 'A';
        else if(c == 'A')   rc = 'U';
        return rc;
    }

    std::string to_rna(const std::string& dna)  {
        std::string rna(dna);
        to_neutral(rna);
        to_final(rna);
        return rna;
    }
}
