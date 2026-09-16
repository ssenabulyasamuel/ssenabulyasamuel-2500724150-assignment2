#include <iostream>

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

bool isValid(long long number) {
	int size = getSize(number);

	bool validPrefix = prefixMatched(number, 4) ||
					   prefixMatched(number, 5) ||
					   prefixMatched(number, 6) ||
					   prefixMatched(number, 37);

	int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);

	return size >= 13 && size <= 16 && validPrefix && total % 10 == 0;
}

int sumOfDoubleEvenPlace(long long number) {
	int sum = 0;
	number /= 10;

	while (number > 0) {
		sum += getDigit(static_cast<int>((number % 10) * 2));
		number /= 100;
	}

	return sum;
}

int getDigit(int number) {
	if (number < 10) {
		return number;
	}

	return number / 10 + number % 10;
}

int sumOfOddPlace(long long number) {
	int sum = 0;

	while (number > 0) {
		sum += static_cast<int>(number % 10);
		number /= 100;
	}

	return sum;
}

bool prefixMatched(long long number, int d) {
	return getPrefix(number, getSize(d)) == d;
}

int getSize(long long d) {
	int size = 0;

	while (d > 0) {
		d /= 10;
		size++;
	}

	return size;
}

long long getPrefix(long long number, int k) {
	int numberOfDigits = getSize(number);

	while (numberOfDigits > k) {
		number /= 10;
		numberOfDigits--;
	}

	return number;
}

int main() {
	long long number;

	std::cout << "Enter a credit card number: ";
	std::cin >> number;

	if (isValid(number)) {
		std::cout << number << " is valid\n";
	} else {
		std::cout << number << " is invalid\n";
	}

	return 0;
}