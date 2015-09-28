#ifndef BOB_H_
#define BOB_H_

#include <string>

namespace bob	{

	extern std::string hey(const std::string& input);
	extern bool is_yelling_string(const std::string& input);
	extern bool is_question_string(const std::string& input);
	extern bool is_nothing_string(const std::string& input);
}

#endif
