//
// Created by mlabouri on 11/22/21.
//

#include "convert.hpp"

size_t	strLen(const char* str) {
	int	i;

	if (str != NULL) {
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

char	cInSet(char c, const char* set) {
	for (int i = 0; set[i]; i++) {
		if (c == set[i])
			return (c);
	}
	return (0);
}

std::string trimWhiteSpaces(char* s) {
	char* trimmed;

	trimmed = s;
	for (int i = 0; s[i]; i++) {
		if (!cInSet(s[i], " \n\r\t"))
			break;
		trimmed++;
	}

	std::string trimmedStr;
	for (int i = strLen(trimmed) - 1; trimmed[i]; i--) {
		if (!cInSet(trimmed[i], " \n\r\t\0")) {
			trimmedStr = static_cast<std::string>(trimmed).substr(0, i+1);
			break;
		}
	}
	return trimmedStr;
}
