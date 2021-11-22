//
// Created by Millefeuille on 09/11/2021.
//

#include "convert.hpp"

eModeAnswer defineModeAnswer(std::string arg, eTypeParam type, char* answer) {
	long answerBuffer;

	if (arg.length() > 1 && type == alpha) {
		return invalid;
	}
	answerBuffer = std::strtol(&arg[0], NULL, 10);
	if (answerBuffer < 0 || answerBuffer > 255) {
		return invalid;
	}
	*answer = static_cast<char> (answerBuffer);
	if (answerBuffer < 32 || answerBuffer > 126) {
		return valid;
	}
	return displayable;
}

eModeAnswer defineModeAnswer(std::string arg, eTypeParam type, int* answer) {
	long answerBuffer;

	if (arg.length() > 1 && type == alpha) {
		return invalid;
	}
	answerBuffer = std::strtol(&arg[0], NULL, 10);
	if (answerBuffer > INT64_MAX || answerBuffer < INT64_MIN) {
		return invalid;
	}
	*answer = static_cast<int> (answerBuffer);
	return valid;
}