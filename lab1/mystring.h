#pragma once
#include<iostream>
class myString {
public:
	myString();
	myString(const char* p);
	myString(const myString& S);
	~myString();
	const char* get_string();
	const char* set_string(const char* p = NULL);
	const char* append(const char* p = NULL);
	int get_lenth();
private:
	char* m_pbuf;
};