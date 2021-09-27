//
// Created by millefeuille on 3/22/21.
//

#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		for (char c = *argv[i]; c; c = *++argv[i]) {
			if (c >= 'a' && c <= 'z')
				c -= 'a' - 'A';
			std::cout << c;
		}
	}
	std::cout << std::endl;
}