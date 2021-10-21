#include"xuesheng.h"
#include<iostream>
#include<string>
using namespace std;
namespace N20281272 {
	CStudentList::CStudentList()
	{
		head_stu = NULL;
		tail_stu = NULL;
		ncount = 0;
	}

	CStudentList::CStudentList(const student& stu)
	{
		head_stu = new student(stu);
		tail_stu = head_stu;
		ncount=1;
	}

	CStudentList::CStudentList(const CStudentList& stu)
	{
		int i;
		student* p = stu.head_stu;
		head_stu = NULL;
		tail_stu = NULL;
		ncount = 0;
		for (i = 0; i < stu.ncount; i++) {
			add_student(*p);
			p = p->getNext();
		}
	}

	CStudentList& CStudentList::operator=(const CStudentList& stu)
	{
		if (this != &stu) {
			int i;
			student* p = head_stu;
			//删除原来的链表
			for (i = 0; i < ncount; i++) {
				p = head_stu;
				head_stu = head_stu->getNext();
				delete p;
			}
			head_stu = NULL;
			tail_stu = NULL;
			ncount = 0;
			p = stu.head_stu;
			for (i = 0; i < stu.ncount; i++) {
				this->add_student(*p);
				p = p->getNext();
			}
		}
		return *this;
	}

	CStudentList::~CStudentList()
	{
		int i;
		student* p = head_stu;
		for (i = 0; i < ncount; i++) {
			p = head_stu;
			head_stu = head_stu->getNext();
			cout << p->getScore() << endl;			
			delete p;

		}
	}

	void CStudentList::add_student(student stu) {
		student* p;
		if (ncount == 0) {
			head_stu = new student(stu);
			tail_stu = head_stu;
			ncount++;
		}
		else {
			p = new student(stu);
			//修改尾指针
			tail_stu->getNext() = p;
			tail_stu = tail_stu->getNext();
			ncount++;
		}
	}

	void CStudentList::display() {
		int i;
		student* p = head_stu;
		cout << "学号\t姓名\t专业\t成绩" << endl;
		for (i = 0; i < ncount; i++) {
			cout << p->getNumber() << "\t" << p->getName() << "\t" << p->getMajor() << "\t" << p->getScore() << endl;
			p = p->getNext();
		}
	}

	void CStudentList::display(double low, double high) {
		int i;
		student* p = head_stu;
		cout << "学号\t姓名\t专业\t成绩" << endl;
		for (i = 0; i < ncount; i++) {
			if (p->getScore() <= high && p->getScore() >= low)
				cout << p->getNumber() << "\t" << p->getName() << "\t" << p->getMajor() << "\t" << p->getScore() << endl;
			p = p->getNext();
		}
	}

	void CStudentList::delete_student(long number){
		int i;
		student* p, * q;
		if (head_stu != NULL) {
			if (head_stu->getNumber() == number) {
				p = head_stu;
				head_stu = head_stu->getNext();
				delete p;
				ncount--;
				return;
			}
			else {
				for (i = 0, p = head_stu; i < ncount; i++) {
					q = p;
					p = p->getNext();
					if (p->getNumber() == number) {
						if (p != tail_stu) {
							q->getNext() = p->getNext();
							delete p;
							ncount--;
							return;
						}
						else {
							tail_stu = q;
							delete p;
							ncount--;
							return;
						}
					}
				}
			}
		}
		cout << "无此学号的学生" << endl;
	}

	student*& CStudentList::getByName(const char* name)
	{
		student* p=head_stu;
		int i;
		for (i = 0; i < ncount; i++) {
			if (!strcmp(p->getName(), name))
				return p;
			p = p->getNext();
		}
		p = NULL;
		cout << "没有找到学生" << endl;
		return p;
	}

	student*& CStudentList::modifyScore(const char* name, double score)
	{
		student* p = getByName(name);
		if (p == NULL) {
			return p;
		}
		p->modifyScore(score);
		return p;
	}

	//student类

	student::student()
	{
		number = 0;
		score = 0;
		next = NULL;
	}

	//student::student(long number2, const char* name2, const char* major2, double score2, student* next2):name(name2),major(major2)
	//{
	//	number = number2;
	//	name.set_string(major2);
	//	major.set_string(major2);
	//	score = score2;
	//	next = next2;
	//}


	student::student(const student& stu)
	{
		number = stu.number;
		name = stu.name;
		major = stu.major;
		score = stu.score;
		next = stu.next;
	}

	void student::fixpointer(student* p)
	{
		next = p;
	}

	student& student::modifyScore(double SCORE)
	{
		score = SCORE;
		return *this;
	}

	student& student::operator=(const student& stu)
	{
		if (this != &stu) {
			number = stu.number;
			major = stu.major;
			name = stu.name;
			score = stu.score;
			next = stu.next;
		}
		return *this;
	}

}