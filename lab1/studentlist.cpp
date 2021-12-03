#include"studentlist.h"
#include"xuesheng.h"
#include"mystring.h"
#include<iostream>
//using namespace std;
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
	ncount = 1;
}

CStudentList::CStudentList(const CStudentList& stu)
{
	int i;
	student* p = stu.head_stu;
	head_stu = NULL;
	tail_stu = NULL;
	ncount = 0;
	for (i = 0; i < stu.ncount; i++) {
		add_student(p);
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
			add_student(p);
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

void CStudentList::add_student(student* stu) {
	student* p;
	CGraduate* q;
	if (ncount == 0) {
		if (dynamic_cast<CGraduate*>(stu)) {
			q = dynamic_cast<CGraduate*>(stu);
			head_stu = new CGraduate(*q);
		}
		else head_stu = new student(*stu);
		tail_stu = head_stu;
		ncount++;
	}
	else {
		if (dynamic_cast<CGraduate*>(stu)) {
			q = dynamic_cast<CGraduate*>(stu);
			p = new CGraduate(*q);
		}
		else p = new student(*stu);
		//修改尾指针
		tail_stu->getNext() = p;
		tail_stu = tail_stu->getNext();
		ncount++;
	}
}

void CStudentList::display() {
	int i;
	student* p = head_stu;
	//cout << "学号\t姓名\t专业\t成绩" << endl;
	for (i = 0; i < ncount; i++) {
		p->display();
		cout << endl;
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

void CStudentList::delete_student(long number) {
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
	student* p = head_stu;
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

CStudentList& CStudentList::read_txt(istream& in)
{
	if (clear() == 0) {
		cout << "引用数大于1，无法读取" << endl;
		return *this;
	}
	int sum, flag;
	in >> sum;
	student* t;
	for (int i = 0; i < sum; i++) {
		in >> flag;
		if (flag == 1) t = new student;
		else t = new CGraduate;
		t->read_txt(in);
		add_student(t);
		delete t;
	}
	return*this;
}

CStudentList& CStudentList::read_bin(istream& in)
{
	if (clear() == 0) {
		cout << "引用数大于1，无法读取" << endl;
		return *this;
	}
	int sum, flag;
	student* t;
	in.read((char*)&sum, sizeof(int));
	for (int i = 0; i < sum; i++) {
		in.read((char*)&flag, sizeof(int));
		if (flag == 1) t = new student;
		else t = new CGraduate;
		t->read_bin(in);
		add_student(t);
		delete t;
	}
	return *this;
}

void CStudentList::write_txt(ostream& o)
{
	int i;
	student* p = head_stu;
	int flag;
	o << ncount << endl;
	for (i = 0; i < ncount; i++) {
		flag = 1;
		if (dynamic_cast<CGraduate*>(p)) {
			flag = 2;
		}
		o << flag << " ";
		p->write_txt(o);
		o << endl;
		p = p->next;
	}
}

void CStudentList::write_bin(ostream& o)
{
	student* p = head_stu;
	int i, flag;
	o.write((char*)&ncount, sizeof(int));
	for (i = 0; i < ncount; i++) {
		flag = 1;
		if (dynamic_cast<CGraduate*>(p)) {
			flag = 2;
		}
		o.write((char*)&flag, sizeof(int));
		p->write_bin(o);
		p = p->next;
	}
}

int CStudentList::clear()
{
	int i;
	student* p = head_stu;
	for (i = 0; i < ncount; i++) {
		if (p->ref != 0) return 0;
	}
	p = head_stu;
	for (i = 0; i < ncount; i++) {
		head_stu = head_stu->next;
		delete(p);
		p = head_stu;
	}
	head_stu = NULL;
	tail_stu = NULL;
	ncount = 0;

	return 1;
}

student* CStudentList::operator[](const int idx)
{
	int i;
	student* p = head_stu;
	for (i = 0; i < idx; i++) {
		p = p->next;
	}
	return p;
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
//	cout << "学号\t姓名\t专业\t成绩" << endl;
	for (i = 0; i < count; ++i) {
		p->pstu->display();
		cout << endl;
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

void CAssociation::clear()
{
	int i;
	for (i = 0; i < count; i++) {
		del(head->pstu->number);
	}
	count = 0;
	head = NULL;
	tail = NULL;
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

CAssociation& CAssociation::read_txt(istream& in)
{
	clear();
	name.read_txt(in);
	int sum, i, flag;
	student* p;
	in >> sum;
	for (i = 0; i < sum; i++) {
		in >> flag;
		if (flag == 1) p = new student;
		else p = new CGraduate;
		p->read_txt(in);
		add(p);
	}
	return *this;
}

CAssociation& CAssociation::read_bin(istream& in)
{
	clear();
	name.read_bin(in);
	int sum, i, flag;
	student* p;
	in.read((char*)&sum, sizeof(int));
	for (i = 0; i < sum; i++) {
		in.read((char*)&flag, sizeof(int));
		if (flag == 1) p = new student;
		else p = new CGraduate;
		p->read_bin(in);
		add(p);
	}
	return *this;
}

void CAssociation::write_txt(ostream& o)
{
	name.write_txt(o);
	o << endl;
	o << count << endl;
	CNode_Association* p = head;
	int i, flag;
	for (i = 0; i < count; i++) {
		flag = 1;
		if (dynamic_cast<CGraduate*>(p->pstu)) {
			flag = 2;
		}
		o << flag << " ";
		p->pstu->write_txt(o);
		o << endl;
		p = p->next;
	}
}

void CAssociation::write_bin(ostream& o)
{
	name.write_bin(o);
	o.write((char*)&count, sizeof(int));
	int i, flag;
	CNode_Association* p = head;
	for (i = 0; i < count; i++) {
		flag = 1;
		if (dynamic_cast<CGraduate*>(p->pstu)) {
			flag = 2;
		}
		o.write((char*)&flag, sizeof(int));
		p->pstu->write_bin(o);
		p = p->next;
	}
}
