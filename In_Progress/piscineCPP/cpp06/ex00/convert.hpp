//
// Created by Millefeuille on 09/11/2021.
//

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>


enum eTypeParam {
	undType,
	alpha,
	num
};

enum eModeAnswer {
	invalid,
	valid,
	displayable
};

struct sAllTypesModesAnswer {
	char		c;
	eModeAnswer	cA;
	int			i;
	eModeAnswer	iA;
	float 		f;
	eModeAnswer	fA;
	double		d;
	eModeAnswer	dA;
};


eTypeParam defineTypeParam(std::string arg);

eModeAnswer defineModeAnswer(std::string arg, eTypeParam type, char* answer);
eModeAnswer defineModeAnswer(std::string arg, eTypeParam type, int* answer);

#endif //CONVERT_HPP
