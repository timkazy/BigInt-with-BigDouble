#pragma once
#include <iostream>
#include <vector>
#include <string>

class BigInt {
public:
	BigInt();
	BigInt(long long num);
	BigInt(std::string num);

	BigInt operator+(const BigInt& rhs);
	BigInt& operator+=(const BigInt& rhs);
	BigInt operator+(const long long& rhs);
	BigInt& operator+=(const long long& rhs);
	BigInt operator+(const std::string& rhs);
	BigInt& operator+=(const std::string& rhs);

	BigInt operator-(const BigInt& rhs);
	BigInt& operator-=(const BigInt& rhs);
	BigInt operator-(const long long& rhs);
	BigInt& operator-=(const long long& rhs);
	BigInt operator-(const std::string& rhs);
	BigInt& operator-=(const std::string& rhs);

	BigInt operator*(const BigInt& rhs);
	BigInt& operator*= (const BigInt& rhs);
	BigInt operator*(const long long& rhs);
	BigInt& operator*= (const long long& rhs);
	BigInt operator*(const std::string& rhs);
	BigInt& operator*= (const std::string& rhs);

	BigInt operator/(const BigInt& rhs);
	BigInt& operator/=(const BigInt& rhs);
	BigInt operator/(const long long& rhs);
	BigInt& operator/=(const long long& rhs);
	BigInt operator/(const std::string& rhs);
	BigInt& operator/=(const std::string& rhs);

	BigInt operator%(const BigInt& rhs);
	BigInt& operator%=(const BigInt& rhs);
	BigInt operator%(const long long& rhs);
	BigInt& operator%=(const long long& rhs);
	BigInt operator%(const std::string& rhs);
	BigInt& operator%=(const std::string& rhs);

	BigInt& operator=(const BigInt& rhs);
	BigInt& operator=(const long long& rhs);
	BigInt& operator=(const std::string& rhs);

	BigInt& operator ++();
	BigInt& operator ++(int);
	BigInt& operator --();
	BigInt& operator --(int);

	friend std::istream& operator>>(std::istream& in, BigInt& rhs);
	friend std::ostream& operator<<(std::ostream& out, const BigInt& rhs);

	bool operator<(const BigInt& rhs) const;
	bool operator<=(const BigInt& rhs) const;
	bool operator>(const BigInt& rhs) const;
	bool operator>=(const BigInt& rhs) const;
	bool operator==(const BigInt& rhs) const;
	bool operator!=(const BigInt& rhs) const;
	bool operator<(const long long& rhs) const;
	bool operator<=(const long long& rhs) const;
	bool operator>(const long long& rhs) const;
	bool operator>=(const long long& rhs) const;
	bool operator==(const long long& rhs) const;
	bool operator!=(const long long& rhs) const;
	bool operator<(const std::string& rhs) const;
	bool operator<=(const std::string& rhs) const;
	bool operator>(const std::string& rhs) const;
	bool operator>=(const std::string& rhs) const;
	bool operator==(const std::string& rhs) const;
	bool operator!=(const std::string& rhs) const;

	std::vector<int> digits;
	bool is_negative = false;
};
