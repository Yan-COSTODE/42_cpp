#include "Fixed.hpp"

int main(void)
{
	Fixed a(5.2f);
	Fixed b(9.8f);
	Fixed c(4.6f);

	std::cout << "a: " << a << ", b:" << b << ", c: " << c <<std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a + c > b: " << (a + c > b) << std::endl;
	std::cout << "a + c < b: " << (a + c < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a + c >= b: " << (a + c >= b) << std::endl;
	std::cout << "a + c <= b: " << (a + c <= b) << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "c++: " << c++ << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "++c: " << ++c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c: " << c << std::endl;
	return 0;
}