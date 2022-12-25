#include <iostream>
#include "BigDouble.h"
#include "BigInt.h"


int main() {
	BigInt a = std::string("50");
	BigInt b("26");
	
	std::cout << "BigInt small" << std::endl;
	std::cout << "sub: " << a - b << std::endl;
	std::cout << "sum: " << a + b << std::endl;
	std::cout << "mult: " << a * b << std::endl;
	std::cout << "div: " << a / b << std::endl;
	std::cout << std::endl;

	BigInt l_a("4432716487354363464134251242353");
	BigInt l_b("-32135325345342");

	std::cout << "BigInt large" << std::endl;
	std::cout << l_a << " " << l_b << std::endl;
	std::cout << "sum: " << l_a + l_b << std::endl;
	std::cout << "sum: " << l_b + l_a << std::endl;
	std::cout << "sub: " << l_a - l_b << std::endl;
	std::cout << "sub: " << l_b - l_a << std::endl;
	std::cout << "mult: " << l_a * l_b << std::endl;
	std::cout << "div: " << l_a / l_b << std::endl;
	std::cout << std::endl;

	std::string str = "321412421";
	BigDouble d_a = str;
	BigDouble d_b("3211/2537468972346283746832158");

	std::cout << "BigDouble" << std::endl;
	std::cout << d_a << " " << d_b << std::endl;
	std::cout << "sum: " << d_a + d_b << std::endl;
	std::cout << "sum: " << d_b + d_a << std::endl;
	std::cout << "sub: " << d_a - d_b << std::endl;
	std::cout << "sub: " << d_b - d_a << std::endl;
	std::cout << "mult: " << d_a * d_b << std::endl;
	std::cout << "div: " << d_a / d_b << std::endl;
	std::cout << (d_a >= d_b) << std::endl;
	std::cout << std::endl;
	return 0;
}
