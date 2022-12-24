#pragma once

class String
{
public:
	String();
	String(const char* str);
	String(const String& str);
	String(const String& str, size_t pos, size_t len);
	~String();

	String& operator= (const char* str);
	char& operator[] (std::size_t pos);
	bool operator< (String& str);
	bool operator== (String& str);
	friend std::ostream& operator<< (std::ostream&, String& str);

	size_t find(const String& str, size_t pos) const;
private:
	std::size_t size;
	std::size_t capacity;
	char* pointer;
};