#include <iostream>
#include <cstring>
#include <cmath>
#include "String.h"
//----------------------------------CONSTRUCTORS-AND-DESTRUCTOR----------------------------------------//
String::String(): size(0), capacity(0), pointer(nullptr) {}
String::String(const char* str): size(strlen(str)), capacity(strlen(str)), pointer(new char[capacity]) {
	for (int i = 0; i < capacity; i++) {
		pointer[i] = str[i];
	}
}
String::String(const String& str) {
	size = str.size;
	capacity = str.capacity;
	pointer = new char[capacity];
	for (int i = 0; i < capacity; i++) {
		pointer[i] = str.pointer[i];
	}
}
String::String(const String& str, size_t pos, size_t len = SIZE_MAX) {
	len = std::min(strlen(str.pointer) - pos, len);
	for (int i = pos; i < len; i++) {
		pointer[i] = str.pointer[i];
	}
}
String::~String() {
	if (pointer != nullptr) { delete[] pointer; }
}
//------------------------------------------OPERATORS--------------------------------------------------//
String& String::operator= (const char* str) {
	size = strlen(str);
	capacity = strlen(str);
	delete[] pointer;
	pointer = new char[capacity];
	for (int i = 0; i < capacity; i++) {
		pointer[i] = str[i];
	}
	return *this;
}
char& String::operator[] (std::size_t pos) {
	try {
		if (0 <= pos < size) { return pointer[pos]; }
		else { throw std::runtime_error("index out of range!"); }
	}
	catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << "\n";
		exit(-1);
	}
}
bool String::operator< (String& str) {
	for (int i = 0; i < std::min(size, str.size); i++) {
		if (pointer[i] != str.pointer[i]) {
			if (pointer[i] > str.pointer[i]) { return true; }
			else { return false; }
		}
	}
	return true;
}
bool String::operator== (String& str) {
	if (size == str.size) {
		for (int i = 0; i < size; i++) {
			if (pointer[i] != str.pointer[i]) { return false; }
		}
	}
	return true;
}
std::ostream& operator<< (std::ostream& out, String& str) {
	for (int i = 0; i < str.size; i++) {
		out << str.pointer[i];
	}
	return out;
}
//-----------------------------------------METHODS-----------------------------------------------------//
size_t String::find(const String& str, size_t pos = 0) const {
	int index = SIZE_MAX;
	for (int i = pos; i < size - str.size + 1; i++) {
		if (pointer[i] == str.pointer[0]) {
			index = i;
			for (int j = 1; j < str.size; j++) {
				if (pointer[i + j] != str.pointer[j]) {
					index = SIZE_MAX;
					break;
				}
			}
			if (index != SIZE_MAX) { return index; }
		}
	}
	return index;
}