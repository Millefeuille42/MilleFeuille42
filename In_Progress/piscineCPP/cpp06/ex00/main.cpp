//
// Created by Millefeuille on 09/11/2021.
//

#include "convert.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Invalid number of arguments!" << std::endl;
		return 1;
	}

	std::string argString = trimWhiteSpaces(argv[1]);
	if (argString.length() < 1) {
		std::cerr << "Invalid argument!" << std::endl;
		return 1;
	}

	double bufferDouble;
	std::istringstream ss(argString);
	ss >> bufferDouble;
	long bufferLong = static_cast<long int>(bufferDouble);

	display(argString, static_cast<char>(bufferLong), bufferLong, ss.fail());
	display(argString, static_cast<int>(bufferLong), bufferLong, ss.fail());
	display(argString, static_cast<float>(bufferDouble), bufferDouble, ss.fail());
	display(argString, bufferDouble, ss.fail());
}
