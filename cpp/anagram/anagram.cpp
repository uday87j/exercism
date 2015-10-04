#include "anagram.h"

#include <cassert>
#include <cctype>
#include <algorithm>
#include <functional>
#include <iostream>


using namespace std;

namespace anagram	{

	std::string tolower(const std::string& str)	{
		std::string s	= str;
		std::transform(str.begin(), str.end(), s.begin(), ::tolower);
		return s;
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
		m_char_count_vec.clear();
		for(auto& c : m_str)	{
			++m_char_map[std::tolower(c)];
		}
		m_char_count_vec.reserve(m_char_map.size());
	}

	std::string anagram_t::word() const	{
		return m_str;
	}

	str_vec_t anagram_t::matches(const str_vec_t& vec)	{
		
		cmap_t cmap;
		str_vec_t anagrams;

		for(auto& s : vec)	{
			cmap.clear();
			if(tolower(s) == m_str)	{
				continue; //Our word isn't an anagram of itself
			}
			for(auto& c : s)	{
				++cmap[std::tolower(c)];
			}
			if(cmap == m_char_map)	{
				anagrams.push_back(s);
			}
		}

		return anagrams;
	}

	str_vec_t anagram_t::matches_v1(const str_vec_t& vec)	{
		str_vec_t anagrams;

		for(auto& s : vec)	{
			cout << s << endl;

			auto is_anagram	= true;
			m_char_count_vec.clear();

			// For each candidate string,
			// check if it has same char as our m_str
			for(auto& c : s)	{
				cout << "Checking char: " << c << endl;
				auto itr	= m_char_map.find(c);
				if(itr == m_char_map.end())	{
					is_anagram	= false;
					break;
				}
				else	{
					// Keep count of this char
					// Maintain 1-to-1 order w.r.t map's key
					// std::map guarantees to store char in alphabetial (sorted) order
					//WARNING: This code will not run & will hang!!!
					//auto index	= std::distance(itr, m_char_map.begin());
					//++m_char_count_vec[index];
				}
			}
			cout << "Done checking letters\n";

			if(is_anagram)	{	// This is still a potential anagram
				cout << s << " might be anagram" << endl;

				//Check if this string is indeed an anagram
				//This string has exactly the same letters as our word
				//We now check for respective char count
				assert(m_char_map.size() == m_char_count_vec.size());
				
				auto vitr	= m_char_count_vec.begin();

				for(auto& m : m_char_map)	{
					if(m.second != *vitr)	{
						is_anagram	= false;
						break;//Not an anagram
					}
					++vitr;
				}

				if(is_anagram)	{
					cout << s << " is anagram" << endl;
					anagrams.push_back(s);
				}
			}
			cout << "End loop\n";
		}

		cout << "Return\n";
		return anagrams;
	}
	
	anagram_t::~anagram_t()	{
	}

	anagram_t anagram(const std::string& str)	{
		return anagram_t(str);
	}
}
