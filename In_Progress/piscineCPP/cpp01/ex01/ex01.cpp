//
// Created by millefeuille on 23/03/2021.
//

# include <string>
# include <iostream>

void memoryLeak()
{
	std::string* panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete(panthere);
}

int main() {
	memoryLeak();
	memoryLeak();
	memoryLeak();
	memoryLeak();
	memoryLeak();
	memoryLeak();
}