#include "hamming.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

namespace hamming	{

	std::uint32_t compute(const std::string& s1,const std::string& s2)	{
		if(s1.size() != s2.size())	{
			throw std::domain_error("Uneven Strings");
		}
		auto c1_itr	= s1.begin();
		auto diff	= 0;
		for(auto& c2 : s2)	{
			if(*c1_itr != c2)
				++diff;
			++c1_itr;
		}
		return diff;
	}
}
