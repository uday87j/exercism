#ifndef WORD_COUNT_H_
#define WORD_COUNT_H_

#include <string>
#include <map>
#include <cstdint>

namespace word_count	{
	typedef std::map<std::string, int> dict_t;
	extern const dict_t words(const std::string& str);
}

#endif
