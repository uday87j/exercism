#include "word_count.h"

namespace word_count	{
	const dict_t words(const std::string& str)	{
		dict_t wc;
		wc[str]	= 1;
		return wc;
	}
}
