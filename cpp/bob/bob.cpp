#include "bob.h"

#include <cctype>
#include <algorithm>

namespace bob	{

	bool is_yelling_string(const std::string& input)	{
		auto is_yell	= false;
		return std::none_of(begin(input), end(input),
                [](const char c)    {
                    return (std::isalpha(c) && std::islower(c));
                }) &&
                std::any_of(begin(input), end(input), [](const char c)  {
                    return std::isalpha(c);
                });
	}

	bool is_question_string(const std::string& input)	{
		auto pos	= input.find('?');
		if(std::string::npos == pos)	{
			return false;
		}
		auto is_ques	= true;
		// The only other character after '?' allowed is ' '
		return std::all_of(std::next(begin(input), pos + 1), end(input),
                [](const char c)    {
                    return std::isspace(c);
                });
	}

	bool is_nothing_string(const std::string& input)	{
	    return input.empty() ||
	        std::all_of(begin(input), end(input),
                    [](const char c)    {
                        return std::isspace(c);
                    });
	}

	std::string hey(const std::string& input)	{
		if(is_nothing_string(input))	{
			return "Fine. Be that way!";
		}
		if(is_yelling_string(input))	{
			return "Whoa, chill out!";
		}
		if(is_question_string(input))	{
			return "Sure.";
		}
		return "Whatever.";
	}
}
