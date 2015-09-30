#ifndef WORD_COUNT_H_
#define WORD_COUNT_H_

#include <string>
#include <map>
#include <cstdint>

namespace word_count	{
	typedef std::map<std::string, int> dict_t;
    
    extern const char APOS_CHAR;//'\''
    extern const char NULL_CHAR;//'\0'


    extern bool is_char_allowed(const char c);
    extern bool is_apostrophes_allowed(const std::array<char, 3>& str);
	extern const dict_t words(const std::string& str);
}

#endif
