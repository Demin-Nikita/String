#include <iostream>
#include "String.h"

void sort(String** mass, int size);
void out(String** mass, int size);
bool search(String** mass, int size, String& search);
bool findRepeats(String** mass, int size);

int main() {
	int n = 0;
	try {
		std::cout << "Input the number of strings: ";
		std::cin >> n;
		if (!std::cin || std::cin.peek() != '\n' || n < 0 || n > SIZE_MAX) {
			throw std::runtime_error("incorrect size of array!");
		}
	}
	catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return(1);
	}

	char* buff = new char[1024 * 1024];
	std::cout << "Input the string for searching: ";
	std::cin >> buff;
	String str(buff);

	String** s = new String * [n];	
	for (int i = 0; i < n; i++) {
		std::cin >> buff;
		s[i] = new String(buff);
	}

	sort(s, n);

	std::cout << '\n';
	out(s, n);
	std::cout << '\n';

	std::cout << "Repeats: " << findRepeats(s, n) << "; " << "Matches with '" << str << "': " << search(s, n, str) << '\n';
	std::cout << '\n';

	delete[] s;
	return 0;
}

void sort(String** mass, int size) {
	int ind = 0;
	for (int i = 0; i < size - 1; i++) {
		ind = 0;
		String* mx = new String;
		for (int j = i; j < size; j++) {
			if (*mx < *mass[j]) {
				mx = mass[j];
				ind = j;
			}
		}
		if (ind != 0) {
			mass[ind] = mass[i];
			mass[i] = mx;
		}
	}
}

void out(String** mass, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << *(mass[i]) << '\n';
	}
}

bool search(String** mass, int size, String& search) {
	for (int i = 0; i < size; i++) {
		if (mass[i]->find(search, 0) == 0) {
			return true;
		}
	}
	return false;
}

bool findRepeats(String** mass, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (*(mass[i]) == *(mass[j])) { return true; }
		}
	}
	return false;
}