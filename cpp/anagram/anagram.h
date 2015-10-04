#ifndef ANAGRAM_H_
#define ANAGRAM_H_

#include <vector>
#include <string>
#include <map>
#include <cstdint>

namespace anagram	{

	typedef std::vector<std::string> str_vec_t;
	typedef std::map<char, std::uint32_t> cmap_t;

	struct anagram_t	{
		
		anagram_t(const std::string& str);
		anagram_t(const anagram_t&);
		anagram_t()	= delete;
		anagram_t& operator = (const anagram_t&);
		~anagram_t();

		std::string word() const;
		str_vec_t matches(const str_vec_t& vec);
		str_vec_t matches_v1(const str_vec_t& vec);

		private:

		void setup_structures();

		std::string m_str;
		cmap_t m_char_map;
		std::vector<std::uint32_t> m_char_count_vec;

	};
	
	extern anagram_t anagram(const std::string& str);
}
#endif
