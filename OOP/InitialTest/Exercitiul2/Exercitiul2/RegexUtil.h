#pragma once
#include <regex>
#include <string>
#include <iostream>

namespace RegexUtil {
	void tryPattern(std::string str) {
		constexpr const char* message{ "Enter string: " };
		std::regex pattern{ str };

		std::cout << message;
		for (std::string word; std::getline(std::cin, word) && word != "exit";)
		{
			std::cout << '|' << word << "|" << str << "|: " << std::boolalpha << (std::regex_match(word, pattern)) << std::endl;
			std::cout << message;
		}
	}

	void tryRegex() {
		constexpr const char* message{ "Enter regex: " };
		std::cout << message;
		for (std::string reg; std::getline(std::cin, reg) && reg != "close"; )
		{
			tryPattern(reg);
			std::cout << message;
		}
	}
}