//
// Created by Millefeuille on 09/11/2021.
//

#include "convert.hpp"

char	cInSet(char c, const char *set) {
	for (int i = 0; set[i]; i++) {
		if (c == set[i]) {
			return (c);
		}
	}
	return (0);
}

std::string trimWhiteSpaces(char *s) {
	char* trimmed;

	trimmed = s;
	for (int i = 0; s[i]; i++) {
		if (!cInSet(s[i], " \n\r\t"))
			break;
		trimmed++;
	}

	std::string trimmedStr;
	for (int i = strlen(trimmed) - 1; trimmed[i]; i--) {
		if (!cInSet(trimmed[i], " \n\r\t\0")) {
			trimmedStr = static_cast<std::string>(trimmed).substr(0, i+1);
			break;
		}
	}
	return trimmedStr;
}

int	main(int argc, char *argv[]) {
	eTypeParam	type;
	sAllTypesModesAnswer	ret = {};
	std::string	argTrimmed;

	if (argc != 2) {
		std::cerr << "Invalid number of arguments!" << std::endl;
		return 1;
	}
	if (strlen(argv[1]) < 1) {
		std::cerr << "Invalid argument!" << std::endl;
		return 1;
	}

	argTrimmed = trimWhiteSpaces(argv[1]);
	type = defineTypeParam(argTrimmed);
	ret.cA = defineModeAnswer(argTrimmed, type, &ret.c);
	ret.iA = defineModeAnswer(argTrimmed, type, &ret.i);

	// TODO make real output
	std::cout << "char: " << static_cast<int>(ret.c) << " --- " << static_cast<int>(ret.cA) << std::endl;
	std::cout << "char: " << static_cast<int>(ret.i) << " --- " << static_cast<int>(ret.iA) << std::endl;

	return 0;
}