#include"MyString.h"
#include<string>
#include<iostream>
using namespace std;
myString::myString()
{
	m_pbuf = new char('\0');
	cout << "����Ĭ�Ϲ��캯��" << endl;
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
	cout << "�����вι��캯��" << endl;
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
	//cout << "����" << endl;
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

myString& myString::append(myString& S)
{
	int len = strlen(m_pbuf) + S.get_length() + 1;
	char* tmp = new char[len];
	sprintf_s(tmp, len, "%s%s", m_pbuf, S.m_pbuf);
	delete[] m_pbuf;
	m_pbuf = tmp;
	return*this;
}

myString& myString::operator=(const myString& S)
{
	if (this != &S) {
		int len = strlen(S.m_pbuf);
		delete this->m_pbuf;
		this->m_pbuf = new char[len + 1];
		strcpy_s(this->m_pbuf, len+1, S.m_pbuf);
	}
	return *this;
}

int myString::get_length()
{
	return strlen(m_pbuf);
}
void test1() {
	myString str;
	str.set_string("I love C++, ");
	cout << "�ַ������ȣ�" << str.get_length() << "\t" << str.get_string() << endl;
	str.append("yeah!");
	cout << "�ַ������ȣ�" << str.get_length() << "\t" << str.get_string() << endl;
	{
		myString str("I like C++ programming!");
		myString str2(str), str3 = str;
	}
	myString str2;
	cout << str.get_string() << endl;
	str2 = str;
	str2.append(str2);
	cout << str2.get_string() << endl;
}