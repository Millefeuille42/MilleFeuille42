//
// Created by mlabouri on 12/1/21.
//

#ifndef INC_42_ARRAY_HPP
#define INC_42_ARRAY_HPP

template<class arrayType> class Array {
public:
//Constructors-Destructors
	Array() : _len(0), _array(new arrayType[len]) {}

	Array(unsigned int len) : _len(len), _array(new arrayType[_len]) {}

	Array(Array const & src) {*this = src;}

	~Array() {delete _array;}

// Operators overload
	Array& operator=(Array const & src) {
		_len = src.size();
		_array = new arrayType[_len];
		for (unsigned int i = 0; i < _len; i++)
			_array = src[i];
		return *this;
	}

	arrayType& operator[](unsigned int i) {
		if (i < 0 || i > _len)
			throw std::out_of_range("invalid value");
		return (_array[i]);
	}

// Getters-Setters
	unsigned int size() const {
		return _len;
	}

private:
	arrayType* _array;
	unsigned int _len;
};

#endif //INC_42_ARRAY_HPP
