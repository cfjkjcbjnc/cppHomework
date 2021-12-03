#include"xuesheng.h"
#include<iostream>
#include<string>
using namespace std;
	//student¿‡

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

	void student::set_next(student* p)
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
		cout << number << '\t' << name.get_string() << '\t' << major.get_string() << '\t' << score;
	}

	student& student::read_txt(istream& in)
	{
		in >> number;
		in >> name;
		in >> major;
		in >> score;
		return *this;
	}

	student& student::read_bin(istream& in)
	{
		in.read((char*)&number, sizeof(long));
		name.read_bin(in);
		major.read_bin(in);
		in.read((char*)&score, sizeof(double));
		return *this;
	}

	void student::write_txt(ostream& o)
	{
		o << *this;
	}

	void student::write_bin(ostream& o)
	{
		o.write((char*)&number, sizeof(long));
		name.write_bin(o);
		major.write_bin(o);
		o.write((char*)&score, sizeof(double));
	}

	ostream& operator<<(ostream& o, const student& s)
	{
		o << s.number << " " << s.name << " " << s.major << " " << s.score;

		return o;
	}

	istream& operator>>(istream& in, student& s)
	{
		in >> s.number >> s.name >> s.major >> s.score;
		return in;
	}

	void CGraduate::display() const
	{
		student::display();
		cout << '\t' << teacher.get_string();
	}

	CGraduate& CGraduate::read_txt(istream& in)
	{
		student::read_txt(in);
		in >> teacher;
		return *this;
	}

	CGraduate& CGraduate::read_bin(istream& in)
	{
		student::read_bin(in);
		teacher.read_bin(in);
		return *this;
	}

	void CGraduate::write_txt(ostream& o)
	{
		student::write_txt(o);
		o << " " << teacher;
	}

	void CGraduate::write_bin(ostream& o)
	{
		student::write_bin(o);
		teacher.write_bin(o);
	}
