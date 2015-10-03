#include "hamming.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

namespace hamming	{

	std::uint32_t compute(const std::string& s1,const std::string& s2)	{
		if(s1.size() != s2.size())	{
			throw std::domain_error("Uneven Strings");
		}
		auto len	= s1.size();
		auto c1		= s1.begin();
		auto c2		= s2.begin();
		auto diff	= 0;
		for(auto i = 0; i < len; ++i, ++c1, ++c2)	{
			if(*c1 != *c2)
				++diff;
		}
		return diff;
	}
}
