#include "bob.h"

#include <cctype>
#include <algorithm>

namespace bob	{

	bool is_yelling_string(const std::string& input)	{
		auto bool is_yell	= false;
		for(auto& c : input)	{
			if(std::isalpha(c))	{
				if(0 == std::isupper(c))	{
					return false;
				}
				is_yell	= true;
			}
		}
		return is_yell;;
	}

	bool is_question_string(const std::string& input)	{
		auto pos	= input.find('?');
		if(std::string::npos == pos)	{
			return false;
		}
		auto is_ques	= true;
		// The only other character after '?' allowed is ' '
		std::for_each(input.begin() + pos + 1, input.end(), [&](const char c)	{
			if(!std::isspace(c))	{
				is_ques	= false;
			}
		});
		return is_ques;
	}

	bool is_nothing_string(const std::string& input)	{
		if(input.empty())	{
			return true;
		}
		for(auto& c : input)	{
			if(!std::isspace(c))	{
				return false;
			}
		}
		return true;
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
