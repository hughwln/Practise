#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

class myString
{
private:
	char * m_str;
	int m_len;
	static int m_num_strings;
	static const int CINLIM = 80;

public:
	myString();
	myString(const char* s);
	myString(const myString& str);
	~myString();
	int size() const {return m_len;}

	myString & operator=(const myString & str);
	myString & operator=(const char * s);
	char operator[](int i);
	const char operator[](int i) const;

	friend bool operator<(const myString & str1, const myString & str2);
	friend bool operator>(const myString & str1, const myString & str2);
	friend bool operator==(const myString & str1, const myString & str2);
	friend ostream & operator<<(ostream & os, const myString & str);
	friend istream & operator>>(istream & is, myString & str);

	static int HowMany();
};

#endif