
#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>

// A few freebies to get past the first couple of tests.
// These may need to be modified!
sfw::string::string(void)
{
	m_data = new char[m_size = 1]{ '\0' };
}

sfw::string::~string()
{
	if (m_data != nullptr)
	{
		delete[]m_data;
	}
}

size_t sfw::string::length() const
{
	// TODO: is this finished?
	return strlen(m_data);
}


sfw::string::string(size_t size)
{
	m_data = new char[m_size = size + 1]{ '\0' };
}

sfw::string::string(const char * a, size_t size)
{	
	m_size = size;		// - Assign m_size
	m_data = new char[m_size];	// - Allocate dyn. array of chars for m_data
	strncpy_s(m_data, m_size, a, strlen(a) < m_size - 1 ? strlen(a) : m_size - 1);// - Copy the char array into the member char array
	// (expression) ? if true : if false
}

sfw::string::string(const char * a)
{
	// do this, if a is valid
	if (a != nullptr)
	{
		m_size = strlen(a) + 1;		// - Assign m_size
		m_data = new char[m_size];	// - Allocate dyn. array of chars for m_data
		strcpy_s(m_data, m_size, a);// - Copy the char array into the member char array
	}
	else // if a is NOT valid
	{
		m_data = new char[m_size = 1]{ '\0' };
	}
}

sfw::string::string(const string & a)
{
	// null check
	if (a.m_data != nullptr)
	{
		m_size = a.m_size;
		m_data = new char[strlen(a.m_data) + 1];
		strcpy_s(m_data, m_size, a.m_data);
	}
	else
	{
		m_data = new char[m_size = 1]{ '\0' };	// empty string
	}
}

sfw::string::string(string && a)
{
	// steal the memory address and size
	m_size = a.m_size;
	m_data = a.m_data;
	// set the victim to a blank but usable state
	a.m_data = new char[a.m_size = 1]{ '\0' };
}

sfw::string & sfw::string::operator=(const string & a)
{
	if (this != &a)	// self-assignment check
	{
		delete[] m_data;	// delete existing data
		m_size = a.m_size;	// copied their size
		m_data = new char[m_size]; // allocate enough memory to store all of the chars
		strcpy_s(m_data, m_size, a.m_data); // copy their string
	}
	return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	delete[]m_data;		// delete our existing data
	m_size = a.m_size;  // steal the size
	m_data = a.m_data;  // steal the data
	a.m_data = new char[a.m_size = 1] {'\0' } ;// reset the other one
	return *this;
}

sfw::string & sfw::string::operator=(const char * a)
{
	delete[]m_data;
	m_size = strlen(a) + 1;		// - Assign m_size
	m_data = new char[m_size];	// - Allocate dyn. array of chars for m_data
	strcpy_s(m_data, m_size, a);// - Copy the char array into the member char array
	return *this;
}

sfw::string & sfw::string::operator+=(const string & a)
{
	resize(a.length() + length() + 1);
	strcat_s(m_data, m_size, a.cstring());
	return *this;
}

sfw::string & sfw::string::operator+=(const char * a)
{
	
	resize(strlen(a) + length() + 1);
	strcat_s(m_data, m_size, a);
	return *this;
}

sfw::string & sfw::string::operator+=(char a)
{
	// TODO:
	return *this;
}

char & sfw::string::operator[](size_t index)
{
	// TODO: Is this finished?
	return this->m_data[index];
}

const char & sfw::string::operator[](size_t index) const
{
	// TODO: Is this finished?
	return this->m_data[index];
}




size_t sfw::string::size() const
{
	return size_t(m_size - 1);
}

void sfw::string::resize(size_t size)
{
	if (size == 0)
	{
		return;
	}

	if (size == ULLONG_MAX)
	{
		return;
	}

	char *temp = new char[size];
	strncpy_s(temp, size, m_data, m_size);
	delete[]m_data;
	m_size = size;
	m_data = temp;
}

void sfw::string::clear()
{
	// TODO:
	m_data = new char[m_size = 1]{ '\0' };
}

bool sfw::string::empty() const
{
	if (m_data[0] == '\0')
	{
		return true;
	}
	else
	{ 
		return false;
	}
}

const char * sfw::string::cstring() const
{
	return m_data;
}

bool sfw::operator<(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator<(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator<(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator<=(const string & a, const string & b)
{
		if (strcmp(a.cstring(), b.cstring()) <= 0)
		{
			return true; 
		}
		else
		{
			return false;
		}
}

bool sfw::operator<=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator<=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator>(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator>(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator>(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator>=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator>=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator>=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator!=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool sfw::operator!=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool sfw::operator!=(const char * a, const string & b)
{

	if (strcmp(a, b.cstring()) == 0)
	{
		return false; 
	}
	else
	{
		return true;
	}
}

bool sfw::operator==(const string & a, const string & b)
{

	if (strcmp(a.cstring(), b.cstring()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator==(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sfw::operator==(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

sfw::string sfw::operator+(const string & a, const string & b)
{
	string result;
	result += a;
	result += b;
	return result;
}

sfw::string sfw::operator+(const string & a, const char * b)
{
	string result;
	result += a;
	result += b;
	return result;
}

sfw::string sfw::operator+(const char * a, const string & b)
{
	string result;
	result += a;
	result += b;
	return result;
}

sfw::string sfw::operator+(const string & a, char b)
{
	string result;
	result += a;
	result += b;
	return result;
}

sfw::string sfw::operator+(char a, const string & b)
{
	string result;
	result += a;
	result += b;
	return result;
}

std::ostream & sfw::operator<<(std::ostream & os, const string & p)
{
	os << p.cstring();
	return os;
}

std::istream & sfw::operator>>(std::istream & is, string & p)
{
	// TODO:
	char buf[256];
	is >> buf;
	
	p = string(buf);
	
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len)
{
	return string(a);
}
