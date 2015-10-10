#include <string>
#include <cstdint>

namespace food_chain	{
	
	struct verse_traits	{
		typedef std::uint8_t uint_t;
	};
	
	extern std::string sing();
	extern std::string verse(verse_traits::uint_t v);
	extern std::string verses(verse_traits::uint_t v1, verse_traits::uint_t v2);
}
