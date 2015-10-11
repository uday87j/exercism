#include "food_chain.h"

#include <cassert>
#include <vector>

using namespace std;

namespace food_chain	{

    std::vector<std::string> lives{ "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
	
	std::string start_str(const std::string& life)	{
		return "I know an old lady who swallowed a " + life + ".\n";
	}

	std::string fly_str()	{
		return "I don't know why she swallowed the fly. Perhaps she'll die.\n";
	}

	std::string spider_str(const std::string& prefix = "It")	{
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

    std::string lyrics(verse_traits::uint_t i)    {
        switch(i)   {
            case 1:
            	return fly_str();
                break;
            case 2:
            	return spider_str();
                break;
            case 3:
            	return bird_str();
                break;
            case 4:
            	return cat_str();
                break;
            case 5:
            	return dog_str();
                break;
            case 6:
            	return goat_str();
                break;
            case 7:
            	return cow_str();
                break;
            case 8:
            	return horse_str();
                break;
            default:
                assert(0);
                break;
        }
        return "";
    }

	std::string connect_verses(verse_traits::uint_t v)	{
		switch(v)	{
			case 2:
				return swallow_str(lives[v-1], lives[v-2]) + ".\n" + fly_str();
				break;

			case 3:
				return  swallow_str(lives[v-1], lives[v-2]) + spider_str(" that")
						+ connect_verses(v - 1);
				break;

			case 4:
			    ;//Fall through

            case 5:
                ;//Fall through

            case 6:
                ;//Fall through

            case 7:
                return swallow_str(lives[v-1], lives[v-2]) + ".\n"
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
				return start_str(lives[v - 1]) + lyrics(v);
				break;

			case 2:
				return start_str(lives[v - 1]) + spider_str("It") + connect_verses(v);
				break;

			case 3:
				;//Fall through

			case 4:
				;//Fall through

            case 5:
            	;//Fall through

            case 6:
            	;//Fall through

			case 7:
				return start_str(lives[v - 1]) + lyrics(v)
					+ connect_verses(v);
				break;

			case 8:
				return start_str("horse") + lyrics(v);
				break;

			default:
				assert(0);
		}
		return "";
	}
}
