#include "word_count.h"

namespace word_count	{
	const dict_t words(const std::string& str)	{
		dict_t wc;
		//wc[str]	= 1;
        auto word       = std::string("");
        char space_ch   = ' ';
        auto begin_pos  = 0;
        auto pos_space  = str.find(space_ch);
        while(pos_space != std::string::npos)   {
            word        = str.substr(begin_pos, pos_space - begin_pos);
            ++wc[word];
            begin_pos   = pos_space + 1;// Even if this results in npos, it is OK
            pos_space   = str.find(space_ch, pos_space);// This result guarantees that begin_pos remain valid at all times
        }
		return wc;
	}
}
