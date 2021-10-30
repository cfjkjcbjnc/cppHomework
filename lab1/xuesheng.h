#pragma once

#include"mystring.h"
namespace N20281272 {

	class student {
		friend class CStudentList;
		friend class CAssociation;
	public:
		student();
		student(long number2, const char* name2, const char* major2, double score2, student* next2, int ref2) : number(number2), name(name2), major(major2), score(score2), next(next2), ref(ref2) {}
		student(const student& stu);
		void fixpointer(student* p);
		student*& getNext() { return next; }
		long getNumber() { return number; }
		const char* getName() { return name.get_string(); }
		const char* getMajor() { return major.get_string(); }
		double getScore() { return score; }
		student& modifyScore(double SCORE);
		student& operator=(const student& stu);
		void display()const;
		//~student();
	private:
		long number;
		myString name;
		myString major;
		double score;
		int ref;
		student* next;
	};
	
	class CStudentList {
	public:
		CStudentList();
		CStudentList(const student& stu);
		CStudentList(const CStudentList& stu);
		CStudentList& operator=(const CStudentList& stu);
		~CStudentList();
		void add_student(student stu);
		void display();
		void display(double low, double high);
		void delete_student(long number);
		student* get(long number);
		student*& getByName(const char*name);
		student*& modifyScore(const char* name, double score);
	private:
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
		CAssociation(CAssociation& a);
		int check(long number);
		void add(student* p);
		void show()const;
		void del(long number);
		CAssociation& operator=(const CAssociation& a);
	private:
		myString name;
		CNode_Association* head;
		CNode_Association* tail;
		int count;
	};
}