//
// Created by mlabouri on 12/1/21.
//

#ifndef INC_42_ARRAY_HPP
#define INC_42_ARRAY_HPP

#include <stdexcept>

template<class arrayType> class Array {
public:
//Constructors-Destructors
	Array();

	Array(unsigned int len);

	Array(Array<arrayType> const & src);

	~Array();

// Operators overload
	arrayType& operator[](unsigned int i) const;

	Array& operator=(Array const & src);
// Getters-Setters
	unsigned int size() const;

private:
	arrayType* _array;
	unsigned int _len;
};

#include "Array.tpp"

#endif //INC_42_ARRAY_HPP
