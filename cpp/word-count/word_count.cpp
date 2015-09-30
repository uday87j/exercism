#include "word_count.h"

#include <iostream>
#include <cctype>
#include <cassert>
#include <array>

namespace word_count	{

	const char APOS_CHAR	= '\'';
	const char NULL_CHAR	= '\0';

	bool is_char_allowed(const char c)	{
		if(std::isalnum(c))	{
			return true;
		}
	}

	bool is_apostrophes_allowed(const std::array<char, 3>& str)	{
		assert(str.size() == 3);//Only prev, ', post chars needed
		assert(str[1] == APOS_CHAR);
		if(std::isalpha(str[0])
			&& std::isalpha(str[2]))	{
			return true;
		}
		return false;
	}

	const dict_t words(const std::string& str)	{
		dict_t wc;
		std::string word("");
		std::array<char, 3> apos_ctx{ NULL_CHAR, APOS_CHAR, NULL_CHAR };
		auto prev_c	= NULL_CHAR;
		bool in_apos_ctx	= false;
		bool is_start_quote	= false;

		for(auto c : str)	{
			if(in_apos_ctx)	{
				apos_ctx[2]	= c;
				if(is_apostrophes_allowed(apos_ctx))	{
					word.append(apos_ctx.data() + 1, 2);
				}
				in_apos_ctx	= false;
			}
			else if(c == APOS_CHAR)	{
                if(is_start_quote)  {
                    ;//Ignore char as quote ends
                    is_start_quote  = false;
                }
                else if(std::isalpha(prev_c))  {
                    apos_ctx[0]	= prev_c;
                    in_apos_ctx	= true;
                }
                else    {
                    is_start_quote  = true;
                }
			}
			else if(is_char_allowed(c))	{
				word.append(1, std::tolower(c));
			}
			else	{
				if(!word.empty())	{
					++wc[word];
				}
				word.clear();
			}
			prev_c	= c;
		}
		if(!word.empty())	{
			++wc[word];
		}

		for(auto& w : wc)	{
			std::cout << w.first << ": " << w.second << std::endl;
		}

		return wc;
	}

}
