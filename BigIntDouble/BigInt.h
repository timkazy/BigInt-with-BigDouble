#pragma once
#include <iostream>
#include <vector>
#include <string>

class BigInt {
public:
	BigInt();
	BigInt(long long num);
	BigInt(std::string num);

	friend BigInt operator+(const BigInt& lhs, const BigInt& rhs);
	friend BigInt& operator+=(BigInt& lhs, const BigInt& rhs);

	friend BigInt operator-(const BigInt& lhs, const BigInt& rhs);
	friend BigInt& operator-=(BigInt& lhs, const BigInt& rhs);

	friend BigInt operator*(const BigInt& lhs, const BigInt& rhs);
	friend BigInt& operator*=(BigInt& lhs, const BigInt& rhs);

	friend BigInt operator/(const BigInt& lhs, const BigInt& rhs);
	friend BigInt& operator/=(BigInt& lhs, const BigInt& rhs);

	friend BigInt operator%(const BigInt& lhs, const BigInt& rhs);
	friend BigInt& operator%=(BigInt& lhs, const BigInt& rhs);

	BigInt& operator=(const BigInt& rhs);
	BigInt& operator=(const long long& rhs);
	BigInt& operator=(const std::string& rhs);

	BigInt& operator ++();
	BigInt operator ++(int);
	BigInt& operator --();
	BigInt operator --(int);

	friend std::istream& operator>>(std::istream& in, BigInt& rhs);
	friend std::ostream& operator<<(std::ostream& out, const BigInt& rhs);

	friend bool operator<(const BigInt& lhs, const BigInt& rhs);
	friend bool operator<=(const BigInt& lhs, const BigInt& rhs);
	friend bool operator>(const BigInt& lhs, const BigInt& rhs);
	friend bool operator>=(const BigInt& lhs, const BigInt& rhs);
	friend bool operator==(const BigInt& lhs, const BigInt& rhs);
	friend bool operator!=(const BigInt& lhs, const BigInt& rhs);

	std::vector<int> digits;
	bool is_negative = false;
};
