//
// Created by Millefeuille on 09/11/2021.
//

#include "convert.hpp"

int manageWhiteSpace(char c) {
	static char ws[8] = "\n\r\t\v\f ";

	for (int i = 0; i < 8; i++)
		if (ws[i] == c)
			return static_cast<int>(c);
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Invalid number of arguments!" << std::endl;
		return 1;
	}

	std::string argString(argv[1]);
	if (argString.length() < 1) {
		std::cerr << "Invalid argument!" << std::endl;
		return 1;
	}

	double bufferDouble;
	bool working = false;
	int c = manageWhiteSpace(argString[0]);

	if (!cInSet(argString[0], "0123456789")) {
		c = static_cast<int>(argString[0]);
	}

	if (c) {
		bufferDouble = static_cast<double>(c);
	} else {
		std::istringstream ss(argString);
		ss >> bufferDouble;
		working = ss.fail();
	}

	long bufferLong = static_cast<long int>(bufferDouble);

	display(argString, static_cast<char>(bufferLong), bufferLong, working);
	display(argString, static_cast<int>(bufferLong), bufferLong, working);
	display(argString, static_cast<float>(bufferDouble), bufferDouble, working);
	display(argString, bufferDouble, working);
}
