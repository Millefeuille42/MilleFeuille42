//
// Created by mathi on 08-Mar-22.
//

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>
#include "Array.hpp"

#define TP template<class arrayType>
#define ARR Array<arrayType>

//Constructors-Destructors
TP
	ARR::Array() : _len(0) {
		_array = new arrayType[_len];
	}
TP
	ARR::Array(unsigned int len) : _len(len) {
		_array = new arrayType[_len];
	}
TP
	ARR::Array(ARR const & src) {
		*this = src;
	}
TP
	ARR::~Array() {
		delete [] _array;
	}

// Operators overload
TP
arrayType& ARR::operator[](unsigned int i) const {
		if (i >= _len)
			throw std::out_of_range("index out of range");
		return (_array[i]);
	}
TP
	ARR& ARR::operator=(ARR const & src) {
		_len = src.size();
		_array = new arrayType[_len];
		for (unsigned int i = 0; i < _len; i++)
			_array[i] = src[i];
		return *this;
	}

// Getters-Setters
TP
	unsigned int ARR::size() const {
		return _len;
	}

#endif //ARRAY_TPP
