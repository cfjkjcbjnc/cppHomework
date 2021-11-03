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
				head_stu = head_stu->next;
				delete p;
			}
			head_stu = NULL;
			tail_stu = NULL;
			ncount = 0;
			p = stu.head_stu;
			for (i = 0; i < stu.ncount; i++) {
				add_student(*p);
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
			head_stu = head_stu->getNext();
			//cout << p->getScore() << endl;			
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
		student* p = head_stu, * q = head_stu;
		for (i = 0; i < ncount; ++i) {
			if (p->number == number) {
				if (p->ref > 0) {
					cout << "引用数大于0，无法删除" << endl;
					return;
				}
				else if (p == head_stu) {
					head_stu = head_stu->next;
					delete p;
					--ncount;
					return;
				}
				else if (p == tail_stu) {
					tail_stu = q;
					delete p;
					--ncount;
					return;
				}
				else {
					q->next = p->next;
					delete p;
					--ncount;
					return;
				}
			}
		}
		cout << "无此学号的学生" << endl;
	}

	student* CStudentList::get(long number)
	{
		student* p = head_stu;
		int i;
		for (i = 0; i < ncount; ++i) {
			if (p->number == number) {
				return p;
			}
			p = p->next;
		}
		return NULL;
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
		ref = 0;
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
		ref = stu.ref;
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

	void student::display() const
	{
		cout << number << '\t' << name.get_string() << '\t' << major.get_string() << '\t' << score << endl;
	}

	CAssociation::~CAssociation()
	{
		int i;
		CNode_Association* p = head;
		for (i = 0; i < count; ++i) {
			head = head->next;
			--p->pstu->ref;
			delete p;
			p = head;
		}
	}

	CAssociation::CAssociation(CAssociation& a)
	{
		int i;
		count = a.count;
		CNode_Association* p=a.head;
		for (i = 0; i < count; ++i) {
			add(p->pstu);
			p = p->next;
		}
	}

	int CAssociation::check(long number)
	{
		if (count == 0) return 0;
		int i;
		CNode_Association* p = head;
		for (i = 0; i < count; i++) {
			if (p->pstu->getNumber() == number) return 1;
			p = p->next;
		}
		return 0;
	}

	void CAssociation::add(student* p)
	{
		if (p == NULL) return;
		if (!check(p->getNumber())) {
			if (count == 0) {
				head = new CNode_Association(p);
				tail = head;
				++p->ref;
				count++;
			}
			else {
				CNode_Association* tmp = new CNode_Association(p);
				tail->next = tmp;
				tail = tail->next;
				++p->ref;
				count++;
			}
		}
	}

	void CAssociation::show() const
	{
		int i;
		CNode_Association* p = head;
		cout << "社团名字：" << name.get_string() << endl;
		cout << "学号\t姓名\t专业\t成绩" << endl;
		for (i = 0; i < count; ++i) {
			p->pstu->display();
			p = p->next;
		}
	}

	void CAssociation::del(long number)
	{
		int i;
		CNode_Association* p = head, * r = head;
		for (i = 0; i < count; ++i) {
			if (p->pstu->getNumber() == number) {
				--count;
				--p->pstu->ref;
				if (p == head) {
					head = head->next;
					delete p;
				}
				else if (p == tail) {
					tail = r;
					delete p;
				}
				else {
					r->next = p->next;
					delete p;
				}
				break;
			}
			r = p;
			p = p->next;
		}
	}

	CAssociation& CAssociation::operator=(const CAssociation& a)
	{
		int i;
		CNode_Association* p;
		if (this != &a) {
			for (p = head, i = 0; i < count; ++i) {
				del(p->pstu->number);
				p = p->next;
			}
			head = NULL;
			tail = NULL;
			count = 0;
			for (p = a.head, i = 0; i < a.count; ++i) {
				add(p->pstu);
				p = p->next;
			}
		}
		return *this;
	}

	CAssociation CAssociation::operator+(const CAssociation& a)
	{
		CAssociation tmp(*this);
		CNode_Association* p = a.head;
		int i;
		for (i = 0; i < a.count; ++i) {
			tmp.add(p->pstu);
			p = p->next;
		}
		return tmp;
	}

	student& CAssociation::operator[](const int idx)
	{
		if (idx >= count || idx < 0) {
			exit(1);
		}
		int i;
		CNode_Association* p = head;
		for (i = 0; i < idx; ++i) {
			p = p->next;
		}
		return *p->pstu;
	}

}