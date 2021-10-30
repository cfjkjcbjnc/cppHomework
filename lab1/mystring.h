#pragma once
#include<iostream>
#include<cstring>;
class myString {
public:
	myString();
	myString(const char* p);
	myString(const myString& S);
	~myString();
    const char* get_string() const;
	const char* set_string(const char* p = NULL);
	const char* append(const char* p = NULL);
	myString& append(myString& S);
	myString& operator = (const myString & S);
    int get_length() const;
	static int get_count() { return count; }
private:
	char* m_pbuf;
	static int count;
};

void test1();