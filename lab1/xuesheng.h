#pragma once
#include<iostream>
#include<fstream>
#include"mystring.h"

class student {
	friend class CAPP;
	friend class CStudentList;
	friend class CAssociation;
public:
	student();
	virtual ~student() {};
	student(long number2, const char* name2, const char* major2, double score2, student* next2, int ref2) : number(number2), name(name2), major(major2), score(score2), next(next2), ref(ref2) {}
	student(const student& stu);
	void set_next(student* p);
	student*& getNext() { return next; }
	long getNumber() { return number; }
	const char* getName() { return name.get_string(); }
	const char* getMajor() { return major.get_string(); }
	double getScore() { return score; }
	student& modifyScore(double SCORE);
	student& operator=(const student& stu);
	virtual void display()const;
	//~student();	
	friend ostream& operator<<(ostream& o, const student& s);
	friend istream& operator>>(istream& in, student& s);
	virtual student& read_txt(istream& in);
	virtual student& read_bin(istream& in);
	virtual void write_txt(ostream& o);
	virtual void write_bin(ostream& o);
private:
	long number;
	myString name;
	myString major;
	double score;
	int ref;
	student* next;
};

class CGraduate :public student
{
	friend class CStudentList;
	friend class CAssociation;
public:
	virtual ~CGraduate() {}
	virtual void display()const;
	CGraduate() { set_next(NULL); }
	CGraduate(long number2, const char* name2, const char* major2, double score2, student* next2, int ref2, const char* teacher2) :student(number2, name2, major2, score2, next2, ref2), teacher(teacher2) {}
	virtual CGraduate& read_txt(istream& in);
	virtual CGraduate& read_bin(istream& in);
	virtual void write_txt(ostream& o);
	virtual void write_bin(ostream& o);
private:
	myString teacher;
};

