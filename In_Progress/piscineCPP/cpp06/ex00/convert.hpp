//
// Created by Millefeuille on 09/11/2021.
//

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cfloat>
# include <climits>

std::string trimWhiteSpaces(char* s);

void display(std::string const & arg, char val, long buffer, bool fail);
void display(std::string const & arg, int val, long buffer, bool fail);
void display(std::string const & arg, float val, double buffer, bool fail);
void display(std::string const & arg, double val, bool fail);

#endif //CONVERT_HPP
