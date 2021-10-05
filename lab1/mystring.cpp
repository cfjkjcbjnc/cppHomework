#include"MyString.h"
#include<string>
myString::myString()
{
	m_pbuf = new char('\0');
}

myString::myString(const char* p)
{
	if (p == NULL) {
		m_pbuf = new char('\0');
	}
	else {
		m_pbuf = new char[strlen(p) + 1];
		strcpy_s(m_pbuf, strlen(p) + 1, p);
	}
	//set_string(p);
}

myString::myString(const myString& S)
{
	int len = strlen(S.m_pbuf) + 1;
	m_pbuf = new char[len];
	strcpy_s(m_pbuf, len, S.m_pbuf);
}

myString::~myString()
{
	delete[]m_pbuf;
}

const char* myString::get_string()
{
	return m_pbuf;
}

const char* myString::set_string(const char* p)
{
	char* tmp = m_pbuf;
	if (p == NULL) {
		m_pbuf = new char('\0');
		delete tmp;
	}
	else {
		m_pbuf = new char[strlen(p) + 1];
		strcpy_s(m_pbuf, strlen(p) + 1, p);
		delete tmp;
	}
	return m_pbuf;
}

const char* myString::append(const char* p)
{
	if (p == NULL) return m_pbuf;
	char* tmp = m_pbuf;
	int length = strlen(m_pbuf) + strlen(p) + 1;
	m_pbuf = new char[length];
	sprintf_s(m_pbuf, length, "%s%s", tmp, p);
	delete tmp;
	return m_pbuf;
}

int myString::get_lenth()
{
	return strlen(m_pbuf);
}
