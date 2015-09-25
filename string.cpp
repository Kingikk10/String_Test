
#include "string.h"
#include <iostream>
#include <cstring>


// A few freebies to get past the first couple of tests.
// These may need to be modified!
sfw::string::string(void)
{
	// TODO: is this finished?
	m_data = new char[m_size = 1]{ '\0' };
}

sfw::string::~string()
{
	// TODO: is this finished?
	delete[]m_data;
}

size_t sfw::string::length() const
{
	// TODO: is this finished?
	return strlen(m_data);
}





sfw::string::string(size_t size)
{
	// TODO:
}

sfw::string::string(const char * a, size_t size)
{
	// TODO:
}

sfw::string::string(const char * a)
{
	// TODO:
}

sfw::string::string(const string & a)
{
	// TODO:
}

sfw::string::string(string && a)
{
	// TODO:
}

sfw::string & sfw::string::operator=(const string & a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator=(const char * a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(const string & a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(const char * a)
{
	// TODO:
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
	return this->m_data[0];
}

const char & sfw::string::operator[](size_t index) const
{
	// TODO: Is this finished?
	return this->m_data[0];
}




size_t sfw::string::size() const
{
	// TODO:
	return size_t();
}

void sfw::string::resize(size_t size)
{
	// TODO:
}

void sfw::string::clear()
{
	// TODO:
}

bool sfw::string::empty() const
{
	// TODO:
	return false;
}

const char * sfw::string::cstring() const
{
	// TODO:
	return nullptr;
}

bool sfw::operator<(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator<(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const char * a, const string & b)
{
	// TODO:
	return false;
}

sfw::string sfw::operator+(const string & a, const string & b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const string & a, const char * b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const char * a, const string & b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const string & a, char b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(char a, const string & b)
{
	// TODO:
	return string();
}

std::ostream & sfw::operator<<(std::ostream & os, const string & p)
{
	// TODO:
	return os;
}

std::istream & sfw::operator>>(std::istream & is, const string & p)
{
	// TODO:
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len)
{
	// TODO:
	return string();
}
