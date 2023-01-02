#pragma once
#include "BigInt.h"
#include <iostream>

class BigDouble {
public:
	BigDouble(std::string str);
	BigDouble(BigInt num);

	BigDouble operator+(const BigDouble& rhs);
	BigDouble& operator+=(const BigDouble& rhs);
	BigDouble operator+(const long long& rhs);

	BigDouble operator-(const BigDouble& rhs);
	BigDouble& operator-=(const BigDouble& rhs);
	BigDouble operator-(const long long& rhs);


	BigDouble operator*(const BigDouble& rhs);
	BigDouble& operator*=(const BigDouble& rhs);


	BigDouble operator/(const BigDouble& rhs);
	BigDouble& operator/=(const BigDouble& rhs);


	BigDouble& operator=(const BigDouble& rhs);
	BigDouble& operator=(const std::string& rhs);

	BigDouble& operator ++();
	BigDouble operator ++(int);
	BigDouble& operator --();
	BigDouble operator --(int);

	bool operator<(const BigDouble& rhs) const;
	bool operator<=(const BigDouble& rhs) const;
	bool operator>(const BigDouble& rhs) const;
	bool operator>=(const BigDouble& rhs) const;
	bool operator==(const BigDouble& rhs) const;
	bool operator!=(const BigDouble& rhs) const;

	friend std::ostream& operator<<(std::ostream& out, const BigDouble& rhs);
private:
	BigInt numerator;
	BigInt denominator;

	static BigInt GCD(BigInt a, BigInt b);
};
