#include "food_chain.h"

#include <cassert>

using namespace std;

namespace food_chain	{
	
	std::string start_str(const std::string& life)	{
		return "I know an old lady who swallowed a " + life + ".\n";
	}

	std::string fly_str()	{
		return "I don't know why she swallowed the fly. Perhaps she'll die.\n";
	}

	std::string spider_str(const std::string& prefix)	{
		return prefix + " wriggled and jiggled and tickled inside her.\n";
	}

	std::string bird_str()	{
		return "How absurd to swallow a bird!\n";
	}
	
	std::string cat_str()	{
		return "Imagine that, to swallow a cat!\n";
	}

    std::string dog_str()   {
        return "What a hog, to swallow a dog!\n";
    }

    std::string goat_str()  {
        return "Just opened her throat and swallowed a goat!\n";
    }

    std::string cow_str()  {
        return "I don't know how she swallowed a cow!\n";
    }

    std::string horse_str()  {
        return "She's dead, of course!\n";
    }

	std::string swallow_str(const std::string& predator, const std::string& prey)	{
		return "She swallowed the " + predator + " to catch the " + prey;
	}

	std::string connect_verses(verse_traits::uint_t v)	{
		switch(v)	{
			case 2:
				return swallow_str("spider", "fly") + ".\n" + fly_str();
				break;

			case 3:
				return  swallow_str("bird", "spider") + spider_str(" that")
						+ connect_verses(v - 1);
				break;

			case 4:
				return swallow_str("cat", "bird") + ".\n"
						+ connect_verses(v - 1);
				break;

            case 5:
                return swallow_str("dog", "cat") + ".\n"
						+ connect_verses(v - 1);
                break;

            case 6:
                return swallow_str("goat", "dog") + ".\n"
						+ connect_verses(v - 1);
                break;

            case 7:
                return swallow_str("cow", "goat") + ".\n"
						+ connect_verses(v - 1);
                break;

			default:
				assert(0);
		}
		return "";
	}

    std::string verses(verse_traits::uint_t v1, verse_traits::uint_t v2) {
        std::string s   = "";
        for(auto i = v1; i <= v2; ++i)  {
            s   += verse(i) + "\n";
        }
        return s;
    }

    std::string sing()  {
        return verses(1, 8);
    }

	std::string verse(verse_traits::uint_t v)	{
		switch(v)	{
			case 1:
				return start_str("fly") + fly_str();
				break;

			case 2:
				return start_str("spider") + spider_str("It") + connect_verses(v);
				break;

			case 3:
				return start_str("bird") + bird_str()
					+ connect_verses(v);
				break;

			case 4:
				return start_str("cat") + cat_str()
					+ connect_verses(v);
				break;

            case 5:
                return start_str("dog") + dog_str()
					+ connect_verses(v);
                break;

            case 6:
                return start_str("goat") + goat_str()
					+ connect_verses(v);
                break;

            case 7:
                return start_str("cow") + cow_str()
					+ connect_verses(v);
                break;

                case 8:
                return start_str("horse") + horse_str();
                break;

			default:
				assert(0);
		}
		return "";
	}
}
