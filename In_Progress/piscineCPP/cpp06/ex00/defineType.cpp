//
// Created by Millefeuille on 09/11/2021.
//

#include "convert.hpp"

static eTypeParam defineTypeChar(char c) {
	if (std::isdigit(c))
		return num;
	return alpha;
}

eTypeParam defineTypeParam(std::string arg) {
	eTypeParam retType = defineTypeChar(arg[0]);
	bool hasDot = false;

	for (int i = 0; arg[i]; i++) {
		// TODO exception float (. et f)
		if (arg[i] == '.' && !hasDot) {
			hasDot = true;
			continue;
		}
		if (defineTypeChar(arg[i]) != retType)
			return undType;
	}
	return retType;
}