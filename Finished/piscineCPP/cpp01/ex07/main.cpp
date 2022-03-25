//
// Created by millefeuille on 3/23/21.
//

#include <iostream>
#include <fstream>

int	printError(int errNum,  std::string errMessage) {
	std::cerr << errMessage << std::endl;
	return errNum;
}

std::string	performReplace(std::string original, std::string oldPattern, std::string newPattern) {
	size_t	index = 0;

	while ((index = original.find(oldPattern, index)) != std::string::npos) {
		original.replace(index, oldPattern.length(), newPattern);
		index += newPattern.length();
	}
	return original;
}

int main(int argc, char *argv[]) {
	if (argc != 4)
		return printError(1, "Invalid number of arguments!");

	std::string			originalContent;
	std::ifstream		originalFile;
	std::ofstream		newFile(std::string(std::string(argv[1]) + ".replace").c_str());

	originalFile.open(argv[1], std::ios::out);
	if (!originalFile.is_open())
		return printError(1, "Can't open original file!");
	if (!newFile.is_open())
		return printError(1, "Can't open destination file!");
	while (getline(originalFile, originalContent))
		newFile << performReplace(originalContent, argv[2], argv[3]) << std::endl;
	originalFile.close();
	newFile.close();
}