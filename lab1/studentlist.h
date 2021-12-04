#pragma once
#include"xuesheng.h"
#include"studentlist.h"

class CStudentList {
	friend class CAPP;
	public:
	CStudentList();
	CStudentList(const student& stu);
	~CStudentList();
	void add_student(student* stu);
	void display();
	void display(double low, double high);
	void delete_student(long number);
	student* get(long number);
	student*& getByName(const char* name);
	student*& modifyScore(const char* name, double score);
	CStudentList& read_txt(istream& in);
	CStudentList& read_bin(istream& in);
	void write_txt(ostream& o);
	void write_bin(ostream& o);
	int clear();
	student* operator[](const int idx);
private:
	CStudentList(const CStudentList& stu);
	CStudentList& operator=(const CStudentList& stu);
	student* head_stu;
	student* tail_stu;
	int ncount;
};
class CNode_Association {
	friend class CAssociation;
public:
	CNode_Association(student* p) :pstu(p), next(NULL) {};
	CNode_Association(CNode_Association& p) :pstu(p.pstu), next(p.next) {}
private:
	student* pstu;
	CNode_Association* next;

};
class CAssociation {
public:
	CAssociation(const char* name2) :name(name2), head(NULL), tail(NULL), count(0) {}
	~CAssociation();
	int check(long number);
	void add(student* p);
	void show()const;
	void del(long number);
	void clear();
	CAssociation operator+(const CAssociation& a);
	student& operator[](const int idx);
	CAssociation& read_txt(istream& in,CStudentList& S);
	CAssociation& read_bin(istream& in,CStudentList& S);
	void write_txt(ostream& o);
	void write_bin(ostream& o);
private:
	CAssociation(const CAssociation& a);
	CAssociation& operator=(const CAssociation& a);
	myString name;
	CNode_Association* head;
	CNode_Association* tail;
	int count;
};