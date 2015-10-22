#include "beer_song.h"

#include <iostream>
#include <sstream>
#include <boost/lexical_cast.hpp>

using namespace std;


namespace beer  {

    std::string common_str(const uint32_t i)    {
        auto istr   = boost::lexical_cast<string>(i) + " bottles";
        auto pstr   = boost::lexical_cast<string>(i - 1) + " bottles";
        auto astr   = string("one");

        switch(i)   {
            case 0:
                return "No more bottles of beer on the wall, no more bottles of beer.\n"
        "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
                break;

            case 1:
                istr    = "1 bottle";
                pstr    = "no more bottles";
                astr    = "it";
                break;

            case 2:
                pstr    = pstr.replace(
                            pstr.find("bottles"), 7, "bottle");
                break;

            default:
                ;
                break;
        }

        return (istr + " of beer on the wall, " + istr +
                 " of beer.\nTake " + astr + " down and pass it around, " +
                 pstr + " of beer on the wall.\n");
    }

    std::string verse(const uint32_t i)  {
        return common_str(i);
    }

    std::string sing(const int32_t beg_verse, const int32_t end_verse)    {
        auto song   = string("");
        for(auto i = beg_verse; i >= end_verse; --i)    {
            song    += verse(i) + "\n";
        }
        song    = song.replace(song.find_last_of("\n"), 2, "");
        return song;
    }
}
