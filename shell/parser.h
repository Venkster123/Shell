#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <string>

std::vector <std::string> get_flags(std::string line)
{
	std::vector <std::string> flags;
	std::string word;
	int len;

	len = 0;
	for (int i = 0; i < line.length(); i++) {
		if (isspace(line[i]) && len > 0) {
			flags.push_back(word);
			word.clear();
			len = 0;
		} else {
			word += line[i];
			len++;
		}
	}

	if (len > 0)
		flags.push_back(word);

	return flags;
}

#endif