#include "BigDouble.h"

BigDouble& BigDouble::operator=(const BigDouble& rhs) {
	numerator = rhs.numerator;
	denominator = rhs.denominator;
	return *this;
}

BigDouble& BigDouble::operator=(const std::string& rhs) {
	BigDouble right = rhs;
	numerator = right.numerator;
	denominator = right.denominator;
	return *this;
}

BigDouble::BigDouble(std::string str) {
	int slash_pos = 0;

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '/') {
			slash_pos = i;
			break;
		}
	}
	
	if (slash_pos == 0) {
		numerator = str; 
		denominator = "1";
	} else {
		numerator = str.substr(0, slash_pos);
		denominator = str.substr(slash_pos + 1);
	}
}

BigDouble::BigDouble(BigInt num) {
	numerator = num;
	denominator = "1";
}

BigDouble BigDouble::operator+(const BigDouble& rhs) {
	BigDouble left = *this;
	BigDouble right = rhs;

	right.numerator *= left.denominator;
	left.denominator *= right.denominator;
	left.numerator *= right.denominator;
	
	left.numerator += right.numerator;
	
	bool neg = left.numerator.is_negative;
	left.numerator.is_negative = false;
	
	BigInt general = GCD(left.numerator, left.denominator);
	left.numerator /= general;
	left.denominator /= general;
	
	left.numerator.is_negative = neg;
	return left;
}

BigDouble& BigDouble::operator+=(const BigDouble& rhs) {
	*this = *this + rhs;
	return *this;
}

BigDouble BigDouble::operator+(const long long& rhs) {
	BigInt right(rhs);
	return *this + right;
}

BigDouble BigDouble::operator-(const BigDouble& rhs) {
	BigDouble left = *this;
	BigDouble right = rhs;

	right.numerator *= left.denominator;
	left.denominator *= right.denominator;
	left.numerator *= right.denominator;
	
	left.numerator -= right.numerator;

	bool neg = left.numerator.is_negative;
	left.numerator.is_negative = false;

	BigInt general = GCD(left.numerator, left.denominator);
	left.numerator /= general;
	left.denominator /= general;

	left.numerator.is_negative = neg;
	return left;
}

BigDouble& BigDouble::operator-=(const BigDouble& rhs) {
	*this = *this - rhs;
	return *this;
}

BigDouble BigDouble::operator-(const long long& rhs) {
	BigInt right(rhs);
	return *this - right;
}

BigDouble BigDouble::operator/(const BigDouble& rhs) {
	BigDouble left = *this;
	BigDouble right = rhs;

	left.numerator *= right.denominator;
	left.denominator *= right.numerator;

	bool neg = (left.numerator.is_negative != left.denominator.is_negative);
	left.numerator.is_negative = false;
	left.denominator.is_negative = false;

	BigInt general = GCD(left.numerator, left.denominator);
	left.numerator /= general;
	left.denominator /= general;

	left.numerator.is_negative = neg;
	return left;
}

BigDouble& BigDouble::operator/=(const BigDouble& rhs) {
	*this = *this / rhs;
	return *this;
}

BigDouble BigDouble::operator*(const BigDouble& rhs) {
	BigDouble left = *this;
	BigDouble right = rhs;

	left.numerator *= right.numerator;
	left.denominator *= right.denominator;

	bool neg = left.numerator.is_negative;
	left.numerator.is_negative = false;
	left.denominator.is_negative = false;

	BigInt general = GCD(left.numerator, left.denominator);
	left.numerator /= general;
	left.denominator /= general;

	left.numerator.is_negative = neg;
	return left;
}

BigDouble& BigDouble::operator*=(const BigDouble& rhs) {
	*this = *this * rhs;
	return *this;
}

BigDouble& BigDouble::operator++() {
	return *this = *this + 1;
}

BigDouble BigDouble::operator++(int) {
	*this = *this + 1;
	return *this = *this - 1;
}

BigDouble& BigDouble::operator --() {
	return *this = *this - 1;
}

BigDouble BigDouble::operator --(int) {
	*this = *this - 1;
	return *this = *this + 1;
}

bool BigDouble::operator<=(const BigDouble& rhs) const {
	return !(*this > rhs);
}

bool BigDouble::operator<(const BigDouble& rhs) const {
	BigDouble left_full = *this;
	BigDouble right_full = rhs;
	BigInt left = left_full.numerator * right_full.denominator;
	BigInt right = right_full.numerator * left_full.denominator;
	return left < right;
}

bool BigDouble::operator>=(const BigDouble& rhs) const {
	return !(*this < rhs);
}

bool BigDouble::operator>(const BigDouble& rhs) const {
	BigDouble left_full = *this;
	BigDouble right_full = rhs;
	BigInt left = left_full.numerator * right_full.denominator;
	BigInt right = right_full.numerator * left_full.denominator;
	return left > right;
}

bool BigDouble::operator==(const BigDouble& rhs) const {
	return ((*this <= rhs) && (*this >= rhs));
}

bool BigDouble::operator!=(const BigDouble& rhs) const {
	return !(*this == rhs);
}


BigInt BigDouble::GCD(BigInt a, BigInt b) {
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return GCD(a % b, b);
	return GCD(a, b % a);
}

std::ostream& operator<<(std::ostream& out, const BigDouble& rhs) {
	BigDouble result = rhs;
	if (result.numerator.is_negative) out << '-';
	
	while (result.numerator.digits.size() != 1 && result.numerator.digits.back() == 0) {
		result.numerator.digits.pop_back();
	}

	for (int i = result.numerator.digits.size() - 1; i >= 0; --i) {
		out << result.numerator.digits[i];
	}
	
	
	if (result.denominator != 1) {
		out << " / ";

		while (result.denominator.digits.size() != 1 && result.denominator.digits.back() == 0) {
			result.denominator.digits.pop_back();
		}

		for (int i = result.denominator.digits.size() - 1; i >= 0; --i) {
			out << result.denominator.digits[i];
		}
	}
	return out;
}
