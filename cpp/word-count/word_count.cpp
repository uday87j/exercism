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

		std::array<char, 3> apos_ctx{ NULL_CHAR, APOS_CHAR, NULL_CHAR };//[0] & [2] will contain alpha char that are part of a valid word

		auto prev_c	            = NULL_CHAR;
		auto consider_post_apos	= false;//Currently in a context of precessing APOS_CHAR that is valid
		auto is_apos_quote	    = false;//If APOS_CHAR is start/end of quote, we ignore it

		for(auto c : str)	{

			if(consider_post_apos)	{
				apos_ctx[2]	= c;
				if(is_apostrophes_allowed(apos_ctx))	{
					word.append(apos_ctx.data() + 1, 2);
				}
				consider_post_apos	= false;//Reset flag
			}
			
            else if(c == APOS_CHAR)	{

                if(is_apos_quote)  {
                    ;//Ignore char as quote ends
                    is_apos_quote  = false;//Reset flag
                }
                
                else if(std::isalpha(prev_c))  {
                    apos_ctx[0]	= prev_c;//Start building the context for apostrophes
                    consider_post_apos	= true;
                }
                
                else    {
                    assert(!std::isalpha(prev_c));
                    is_apos_quote  = true;
                }
			}
			
            else if(is_char_allowed(c))	{
                //Valid char, continue building current word
				word.append(1, std::tolower(c));
			}
			
            else	{
                //We hit a space or some non-alphanumeric char that might mean the formation of a complete word
				if(!word.empty())	{
					++wc[word];
				}
				word.clear();
			}
			prev_c	= c;
		}
		if(!word.empty())	{
            // Grab the last word which ended with a valid aplhanumeric char
			++wc[word];
		}

		return wc;
	}

}
