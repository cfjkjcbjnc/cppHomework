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
		head_stu = new student;
		head_stu->number = stu.number;
		head_stu->score = stu.score;
		strcpy_s(head_stu->major, 20, stu.major);
		strcpy_s(head_stu->name, 20, stu.name);
		head_stu->next = NULL;
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
			p = p->next;
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
				head_stu = head_stu->next;
				delete p;
			}
			head_stu = NULL;
			tail_stu = NULL;
			ncount = 0;
			p = stu.head_stu;
			for (i = 0; i < stu.ncount; i++) {
				this->add_student(*p);
				p = p->next;
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
			head_stu = head_stu->next;
			cout << p->score << endl;			
			delete p;

		}
	}

	void CStudentList::add_student(student stu) {
		student* p;
		if (ncount == 0) {
			head_stu = new student;
			strcpy_s(head_stu->major, stu.major);
			strcpy_s(head_stu->name, stu.name);
			head_stu->next = NULL;
			head_stu->number = stu.number;
			head_stu->score = stu.score;
			tail_stu = head_stu;
			ncount++;
		}
		else {
			p = new student;
			strcpy_s(p->major, stu.major);
			strcpy_s(p->name, stu.name);
			p->next = NULL;
			p->number = stu.number;
			p->score = stu.score;
			tail_stu->next = p;
			tail_stu = tail_stu->next;
			ncount++;
		}
	}

	void CStudentList::display() {
		int i;
		student* p = head_stu;
		cout << "学号\t姓名\t专业\t成绩" << endl;
		for (i = 0; i < ncount; i++) {
			cout << p->number << "\t" << p->name << "\t" << p->major << "\t" << p->score << endl;
			p = p->next;
		}
	}

	void CStudentList::display(double low, double high) {
		int i;
		student* p = head_stu;
		cout << "学号\t姓名\t专业\t成绩" << endl;
		for (i = 0; i < ncount; i++) {
			if (p->score <= high && p->score >= low)
				cout << p->number << "\t" << p->name << "\t" << p->major << "\t" << p->score << endl;
			p = p->next;
		}
	}

	void CStudentList::delete_student(long number){
		int i;
		student* p, * q;
		if (head_stu != NULL) {
			if (head_stu->number == number) {
				p = head_stu;
				head_stu = head_stu->next;
				delete p;
				ncount--;
				return;
			}
			else {
				for (i = 0, p = head_stu; i < ncount; i++) {
					q = p;
					p = p->next;
					if (p->number == number) {
						if (p != tail_stu) {
							q->next = p->next;
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
			if (!strcmp(p->name, name))
				return p;

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
		p->score = score;
		return p;
	}

}