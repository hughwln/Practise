#include <cstring>
#include "myString.h"

int myString::m_num_strings = 0;

int myString::HowMany()
{
	return m_num_strings;
}

myString::myString()
{
	m_len = 0;
	m_str = new char[1];
	m_str[0] = '\0';
	m_num_strings++;
}

myString::myString(const char* s)
{
	m_len = strlen(s);
	m_str = new char[m_len+1];
	strcpy(m_str, s);
	m_num_strings++;
}

myString::myString(const myString & str)
{
	m_len = str.m_len;
	m_str = new char[m_len+1];
	strcpy(m_str, str.m_str);
	m_num_strings++;
}

myString::~myString()
{
	m_num_strings--;
	delete []m_str;
}

myString & myString::operator=(const myString & str)
{
	if(this == & str)
		return *this;
	delete []m_str;
	m_len = str.m_len;
	m_str = new char[m_len+1];
	strcpy(m_str, str.m_str);
	return *this;
}

myString & myString::operator=(const char * s)
{
	delete []m_str;
	m_len = strlen(s);
	m_str = new char[m_len+1];
	strcpy(m_str, s);
	return *this;
}

char myString::operator[](int i)
{
	return m_str[i];
}

const char myString::operator[](int i) const
{
	return m_str[i];
}

bool operator<(const myString & str1, const myString & str2)
{
	return (strcmp(str1.m_str, str2.m_str) < 0);
}

bool operator>(const myString & str1, const myString & str2)
{
	return str2<str1;
}

bool operator==(const myString & str1, const myString & str2)
{
	return (strcmp(str1.m_str, str2.m_str) == 0);
}

ostream & operator<<(ostream & os, const myString & str)
{
	os << str.m_str;
	return os;
}

istream & operator>>(istream & is, myString & str)
{
	char temp[myString::CINLIM];
	is.get(temp, myString::CINLIM);
	if(is)
		str = temp;
	while(is && is.get() != '\n')
		continue;
	return is;
}




