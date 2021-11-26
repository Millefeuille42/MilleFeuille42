//
// Created by mlabouri on 11/24/21.
//

#include <string>
#include <sstream>
#include <iostream>
#include <stdint.h>
#include <cstring>
#include <cstdlib>

struct Data
{
	std::string name;
	std::string login;
	int age;
};

uintptr_t serialize(Data* ptr) {
	std::stringstream encodingStream;

	encodingStream << ptr->name << '\1' << ptr->login << '\1' << ptr->age << '\0' << '\1' << '\1';
	std::string* data = new std::string(encodingStream.str());

	return reinterpret_cast<uintptr_t>(data);
}

int writeStringToStream(std::stringstream* stream, char* str) {
	int len = 0;
	for (char c = *str; c && c != 1; c = *++str) {
		*stream << c;
		len++;
	}
	return ++len;
}

Data* deserialize(uintptr_t raw) {
	Data* decoded = new Data;
	std::string* data = reinterpret_cast<std::string*>(raw);
	char *dataStock = const_cast<char *>(data->data());
	std::stringstream decodingStream;

	dataStock += writeStringToStream(&decodingStream, dataStock);
	decoded->name = decodingStream.str();
	decodingStream.str(std::string());
	dataStock += writeStringToStream(&decodingStream, dataStock);
	decoded->login = decodingStream.str();
	decodingStream.str(std::string());
	writeStringToStream(&decodingStream, dataStock);
	decodingStream >> decoded->age;

	decodingStream.flush();
	delete data;

	return decoded;
}

int main() {
	Data* test = new Data;
	Data* ret;

	test->name = "Millefeuille";
	test->login = "mlabouri";
	test->age = 20;

	ret = deserialize(serialize(test));

	std::cout << test->name + "/" + test->login + "/" << test->age << std::endl;
	std::cout << ret->name + "/" + ret->login + "/" << ret->age << std::endl;

	delete test;
	delete ret;
	return 0;
}