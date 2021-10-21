#pragma once
#include<iostream>
#include<cstring>;
class myString {
public:
	myString();
	myString(const char* p);
	myString(const myString& S);
	~myString();
    const char* get_string();
	const char* set_string(const char* p = NULL);
	const char* append(const char* p = NULL);
	myString& append(myString& S);
	myString& operator = (const myString & S);
    int get_length();
private:
	char* m_pbuf;
};

void test1();