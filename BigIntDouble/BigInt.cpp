#include "BigInt.h"

BigInt::BigInt() {
	digits.push_back(0);
	is_negative = false;
}

BigInt::BigInt(long long num) {
	if (num < 0) {
		is_negative = true;
		num *= -1;
	}
	do {
		digits.push_back(num % 10);
		num /= 10;
	} while (num);
}

BigInt::BigInt(std::string num) {
	for (int i = num.size() - 1; i >= 0; --i) {
		if (num[i] == '-') {
			this->is_negative = !this->is_negative;
			continue;
		}
		digits.push_back(num[i] - '0');
	}
}

BigInt BigInt::operator+(const BigInt& rhs) {
	BigInt left = *this;
	BigInt right = rhs;
	int carry = 0;

	if (left.is_negative != right.is_negative) {
		if (left.is_negative) {
			left.is_negative = false;
			return right - left;
		}
		else {
			right.is_negative = false;
			return left - right;
		}
	}

	if (digits.size() < rhs.digits.size()) {
		left = rhs;
		right = *this;
	}

	for (int i = 0; i < right.digits.size(); ++i) {
		left.digits[i] += right.digits[i];
	}

	for (int i = 0; i < left.digits.size(); ++i) {
		left.digits[i] += carry;
		carry = left.digits[i] / 10;
		left.digits[i] %= 10;
	}

	while (carry) {
		left.digits.push_back(carry % 10);
		carry /= 10;
	}
	while (left.digits.size() > 1 && left.digits.back() == 0)
		left.digits.pop_back();
	return left;
}

BigInt& BigInt::operator+=(const BigInt& rhs) {
	*this = *this + rhs;
	return *this;
}

BigInt BigInt::operator+(const long long& rhs) {
	BigInt right(rhs);
	return *this + right;
}

BigInt& BigInt::operator+=(const long long& rhs) {
	*this = *this + rhs;
	return *this;
}

BigInt BigInt::operator+(const std::string& rhs) {
	BigInt right(rhs);
	return *this + right;
}

BigInt& BigInt::operator+=(const std::string& rhs) {
	*this = *this + rhs;
	return *this;
}

BigInt BigInt::operator-(const BigInt& rhs) {
	BigInt left = *this;
	BigInt right = rhs;
	BigInt result;

	if (left.is_negative != right.is_negative) {
		bool sign = left.is_negative;
		left.is_negative = false;
		right.is_negative = false;
		result = left + right;
		result.is_negative = sign;
	}
	else {
		int carry = 0;
		int s = 0;
		bool neg = false;

		if (left < right) {
			neg = true;
		}
		if ((left < right && left.is_negative == false) || (left > right && left.is_negative == true)) std::swap(left, right);
		int l_l = left.digits.size();
		int l_r = right.digits.size();
		for (int i = 0; i < l_l; ++i) {
			if (i < l_r) s = left.digits[i] - right.digits[i] + carry;
			else s = left.digits[i] + carry;
			if (s < 0) {
				s += 10;
				carry = -1;
			}
			else
				carry = 0;
			left.digits[i] = s;
		}
		result = left;
		result.is_negative = neg;
	}
	while (result.digits.size() > 1 && result.digits.back() == 0)
		result.digits.pop_back();
	return result;
}

BigInt& BigInt::operator-=(const BigInt& rhs) {
	*this = (*this - rhs);
	return *this;
}

BigInt BigInt::operator-(const long long& rhs) {
	BigInt right(rhs);
	return *this - right;
}

BigInt& BigInt::operator-=(const long long& rhs) {
	*this = (*this - rhs);
	return *this;
}

BigInt BigInt::operator-(const std::string& rhs) {
	BigInt right(rhs);
	return *this - right;
}

BigInt& BigInt::operator-=(const std::string& rhs) {
	*this = (*this - rhs);
	return *this;
}

BigInt BigInt::operator*(const BigInt& rhs) {
	BigInt left = *this;
	BigInt right = rhs;

	if (*this == 0 || rhs == 0) return 0;

	if (left.is_negative != right.is_negative) {
		left.is_negative = true;
	}
	int left_length = left.digits.size();
	int right_length = right.digits.size();

	std::vector<int> v(left_length + right_length, 0);

	for (int i = 0; i < left_length; i++)
		for (int j = 0; j < right_length; j++) {
			v[i + j] += (left.digits[i]) * (right.digits[j]);
		}
	left_length += right_length;
	left.digits.resize(v.size());

	for (int s, i = 0, t = 0; i < left_length; i++) {
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
		left.digits[i] = v[i];
	}

	while (left.digits.size() > 1 && left.digits.back() == 0)
		left.digits.pop_back();
	return left;
}

BigInt& BigInt::operator*= (const BigInt& rhs) {
	*this = *this * rhs;
	return *this;
}

BigInt BigInt::operator*(const long long& rhs) {
	BigInt right(rhs);
	return *this * right;
}

BigInt& BigInt::operator*= (const long long& rhs) {
	*this = *this * rhs;
	return *this;
}

BigInt BigInt::operator*(const std::string& rhs) {
	BigInt right(rhs);
	return *this * right;
}

BigInt& BigInt::operator*= (const std::string& rhs) {
	*this = *this * rhs;
	return *this;
}

BigInt BigInt::operator/(const BigInt& rhs) {
	BigInt left = *this;
	BigInt right = rhs;
	std::string result;
	if (right == 0) throw("ERROR");
	bool neg = (left.is_negative != right.is_negative);
	left.is_negative = false;
	right.is_negative = false;
	BigInt cur;
	for (int i = left.digits.size() - 1; i >= 0; --i) {
		cur = cur * 10 + left.digits[i];
		int tmp = 0;
		while (cur >= right) {
			cur = cur - right;
			tmp = tmp + 1;
		}
		result += std::to_string(tmp);
	}
	BigInt res(result);
	res.is_negative = neg;
	return res;
}

BigInt& BigInt::operator/=(const BigInt& rhs) {
	*this = (*this / rhs);
	return *this;
}

BigInt BigInt::operator/(const long long& rhs) {
	BigInt right(rhs);
	return (*this / right);
}

BigInt& BigInt::operator/=(const long long& rhs) {
	*this = (*this / rhs);
	return *this;
}

BigInt BigInt::operator/(const std::string& rhs) {
	BigInt right(rhs);
	return (*this / right);
}

BigInt& BigInt::operator/=(const std::string& rhs) {
	*this = (*this / rhs);
	return *this;
}

BigInt BigInt::operator%(const BigInt& rhs) {
	BigInt left = *this;
	BigInt right = rhs;
	std::string result;
	if (right == 0) throw("ERROR");
	bool neg = (left.is_negative != right.is_negative);
	left.is_negative = false;
	right.is_negative = false;
	BigInt cur = 0;
	for (int i = left.digits.size() - 1; i >= 0; --i) {
		cur = cur * 10 + left.digits[i];
		while (cur >= right) {
			cur = cur - right;
		}
	}
	return cur;
}

BigInt& BigInt::operator%=(const BigInt& rhs) {
	*this = (*this % rhs);
	return *this;
}

BigInt BigInt::operator%(const long long& rhs) {
	BigInt right(rhs);
	return (*this % right);
}

BigInt& BigInt::operator%=(const long long& rhs) {
	*this = (*this % rhs);
	return *this;
}

BigInt BigInt::operator%(const std::string& rhs) {
	BigInt right(rhs);
	return (*this % right);
}

BigInt& BigInt::operator%=(const std::string& rhs) {
	*this = (*this % rhs);
	return *this;
}

BigInt& BigInt::operator=(const BigInt& rhs) {
	digits = rhs.digits;
	is_negative = rhs.is_negative;
	return *this;
}

BigInt& BigInt::operator=(const long long& rhs) {
	BigInt right = rhs;
	digits = right.digits;
	return *this;
}

BigInt& BigInt::operator=(const std::string& rhs) {
	BigInt right = rhs;
	digits = right.digits;
	is_negative = right.is_negative;
	return *this;
}

BigInt& BigInt::operator++() {
	return *this = *this + 1;
}
BigInt& BigInt::operator++(int) {
	*this = *this + 1;
	return *this = *this - 1;
}

BigInt& BigInt::operator --() {
	return *this = *this - 1;
}
BigInt& BigInt::operator --(int) {
	*this = *this - 1;
	return *this = *this + 1;
}

std::istream& operator>>(std::istream& in, BigInt& rhs) {
	std::string num;
	in >> num;
	rhs = num;

	return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& rhs) {
	BigInt result = rhs;
	while (result.digits.size() != 1 && result.digits.back() == 0) {
		result.digits.pop_back();
	}
	if (rhs.is_negative) out << '-';

	for (int i = result.digits.size() - 1; i >= 0; --i) {
		out << result.digits[i];
	}

	return out;
}

bool BigInt::operator<=(const BigInt& rhs) const {
	return !(*this > rhs);
}

bool BigInt::operator<(const BigInt& rhs) const {
	BigInt left = *this;
	BigInt right = rhs;
	if (left.is_negative != right.is_negative) {
		if (left.is_negative) {
			return true;
		}
		else {
			return false;
		}
	}

	if (left.digits.size() < right.digits.size()) {
		return (left.is_negative ? false : true);
	}
	else if (left.digits.size() > right.digits.size()) {
		return (left.is_negative ? true : false);
	}
	else {
		if (left.is_negative) {
			swap(left.digits, right.digits);
		}
		for (int i = left.digits.size() - 1; i >= 0; --i) {
			if (left.digits[i] < right.digits[i]) {
				return true;
			}
			if (left.digits[i] > right.digits[i]) {
				return false;
			}
		}
		return false;
	}
}

bool BigInt::operator>=(const BigInt& rhs) const {
	return !(*this < rhs);
}

bool BigInt::operator>(const BigInt& rhs) const {
	BigInt left = *this;
	BigInt right(rhs);
	if (left.is_negative != right.is_negative) {
		if (left.is_negative) {
			return false;
		}
		else {
			return true;
		}
	}

	if (left.digits.size() < right.digits.size()) {
		return (left.is_negative ? true : false);
	}
	else if (left.digits.size() > right.digits.size()) {
		return (left.is_negative ? false : true);
	}
	else {
		if (left.is_negative) {
			swap(left.digits, right.digits);
		}
		for (int i = left.digits.size() - 1; i >= 0; --i) {
			if (left.digits[i] > right.digits[i]) {
				return true;
			}
			if (left.digits[i] < right.digits[i]) {
				return false;
			}
		}
		return false;
	}
}

bool BigInt::operator==(const BigInt& rhs) const {
	return ((*this <= rhs) && (*this >= rhs));
}

bool BigInt::operator!=(const BigInt& rhs) const {
	return !(*this == rhs);
}

bool BigInt::operator<(const long long& rhs) const {
	BigInt right(rhs);
	return *this < right;
}

bool BigInt::operator<=(const long long& rhs) const {
	return !(*this > rhs);
}

bool BigInt::operator>(const long long& rhs) const {
	BigInt right(rhs);
	return *this > right;
}

bool BigInt::operator>=(const long long& rhs) const {
	return !(*this < rhs);
}

bool BigInt::operator==(const long long& rhs) const {
	BigInt right(rhs);
	return *this == right;
}

bool BigInt::operator!=(const long long& rhs) const {
	BigInt right(rhs);
	return !(*this == right);
}

bool BigInt::operator<(const std::string& rhs) const {
	BigInt right(rhs);
	return *this < right;
}

bool BigInt::operator<=(const std::string& rhs) const {
	return !(*this > rhs);
}

bool BigInt::operator>(const std::string& rhs) const {
	BigInt right(rhs);
	return *this > right;
}

bool BigInt::operator>=(const std::string& rhs) const {
	return !(*this < rhs);
}

bool BigInt::operator==(const std::string& rhs) const {
	BigInt right(rhs);
	return *this == right;
}

bool BigInt::operator!=(const std::string& rhs) const {
	BigInt right(rhs);
	return !(*this == right);
}
