#include "anagram.h"

#include <cassert>
#include <cctype>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>


using namespace std;

namespace anagram	{

	std::string tolower(std::string str)	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
	}

	anagram_t::anagram_t(const std::string& str)
		: m_str(str)	{
			setup_structures();
		}

	anagram_t::anagram_t(const anagram_t& a)
		: anagram_t(a.word())	{
			setup_structures();
		}

	anagram_t& anagram_t::operator = (const anagram_t& a)	{
		m_str	= a.word();
		setup_structures();
		return *this;
	}

	void anagram_t::setup_structures()	{
		m_char_map.clear();
        fill_char_map(tolower(m_str), m_char_map);
	}

	std::string anagram_t::word() const	{
		return m_str;
	}

	str_vec_t anagram_t::matches(const str_vec_t& vec)	{
		
		cmap_t cmap;
		str_vec_t anagrams;

        std::copy_if(vec.begin(), vec.end(), std::back_inserter(anagrams),
                [&cmap,this](const std::string& s)   {

                    cmap.clear();
                    
                    auto lower_str  = tolower(s);
                    if(lower_str == m_str)  {
                        return false; //Our word isn't an anagram of itself
                    }
                    
                    fill_char_map(lower_str, cmap);
                    if(cmap == m_char_map)  {
                        return true;                        
                    }
                    
                    return false;
                });

		return anagrams;
	}

	anagram_t::~anagram_t()	{
	}

	anagram_t anagram(const std::string& str)	{
		return anagram_t(str);
	}

    void fill_char_map(const std::string& str, cmap_t& cmap) {
        for(auto& c : str)  {
            ++cmap[c];                
        }
    }
}
