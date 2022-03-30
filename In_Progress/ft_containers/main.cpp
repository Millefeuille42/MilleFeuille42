#define TESTED_TYPE int
#define TESTED_NAMESPACE ft
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>

// --- Class foo
template <typename T>
class foo {
public:
	typedef T	value_type;

	foo(void) : value(), _verbose(false) { };
	foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
	foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
	~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
	void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
	void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
	foo &operator=(value_type src) { this->value = src; return *this; };
	foo &operator=(foo const &src) {
		if (this->_verbose || src._verbose)
			std::cout << "foo::operator=(foo) CALLED" << std::endl;
		this->value = src.value;
		return *this;
	};
	value_type	getValue(void) const { return this->value; };
	void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

	operator value_type(void) const {
		return value_type(this->value);
	}
private:
	value_type	value;
	bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	printSize(vct);

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	printSize(vct2);
	vct2.insert(vct2.begin(), vct. begin() + cut, vct.end());
	printSize(vct2);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	printSize(vct2);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	printSize(vct2);
	return (0);
}
