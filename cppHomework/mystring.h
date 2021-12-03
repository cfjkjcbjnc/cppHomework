#pragma once
#pragma once
#include<iostream>
#include<cstring>;
using namespace std;
class myString {
public:
	myString();
	myString(const char* p);
	myString(const myString& S);
	~myString();
	const char* get_string() const;
	const char* set_string(const char* p = NULL);
	const char* append(const char* p = NULL);
	myString& append(const myString& S);
	int get_length() const;
	static int get_count() { return count; }
	operator const char* () const { return m_pbuf; };
	myString& operator = (const myString& S);
	myString& operator=(const char* str);
	myString operator+(const myString& S);
	myString operator+(const char* str);
	char& operator[](const int idx);
	const char operator[](const int idx) const;
	myString& operator()(const char* str);
	friend ostream& operator<<(ostream& o, const myString& s);
	friend istream& operator>>(istream& in, myString& s);
	myString& read_txt(istream& in);
	myString& read_bin(istream& in);
	void write_txt(ostream& o);
	void write_bin(ostream& o);
private:
	char* m_pbuf;
	static int count;
};

void test1();