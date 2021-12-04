#include<iostream>
#include<fstream>
#include"xuesheng.h"
#include"mystring.h"
#include"studentlist.h"

using namespace std;
class CAPP {
public:
	void run1() {
		char c = 'p';
		student temp;
		char str[20];
		char name[20];
		char major[20];
		char teacher[20];
		long number;
		double low, high, score;
		CStudentList a;
		//CAssociation b("bzzb");
		while (c != '0') {
			cout << "学生信息管理系统" << endl;
			cout << "1 录入学生信息" << endl;
			cout << "2 显示学生信息" << endl;
			cout << "3 删除学生信息" << endl;
			cout << "4 显示某一成绩范围的学生信息" << endl;
			cout << "5 通过名字更改学生成绩" << endl;
			cout << "6 将学生信息写入文件" << endl;
			cout << "7 将文件的学生信息读入" << endl;
			cout << "8 录入研究生信息" << endl;
			cout << "0 退出系统" << endl;
			cout << "请选择操作" << endl;
			cin >> c;
			switch (c) {
			case'1':
			{
				CAssociation b("bzzb");
				cout << "请依次输入学号、姓名、专业和成绩" << endl;
				cin >> number >> name >> major >> score;
				student temp(number, name, major, score, NULL, 0);
				a.add_student(&temp);
				//b.add(a.get(number));
				//b.show();
				cout << endl;
				break;
			}
			case'2':
				a.display();
				//b.show();
				//cout << a;
				cout << endl;
				break;
			case'3':
				cout << "请输入要删除的学生学号" << endl;
				cin >> number;
				a.delete_student(number);
				cout << endl;
				break;
			case'4':
				cout << "请依次输入区间的最小值和最大值" << endl;
				cin >> low >> high;
				a.display(low, high);
				break;
			case'5':
			{
				cout << "依次输入名字,成绩" << endl;
				cin >> str >> score;
				a.modifyScore(str, score);
			}
			case'6':
			{
				ofstream out1("test.txt");
				ofstream out2("test.dat");
				a.write_bin(out2);
				a.write_txt(out1);
				out1.close();
				out2.close();
				break;
			}
			case'7':
			{
			//	ifstream in1("test.txt");
			//	a.read_txt(in1);
			//	in1.close();
				ifstream in2("test.dat");
				a.read_bin(in2);
				in2.close();
				break;
			}
			case '8':
			{
				cout << "请依次输入学号、姓名、专业、成绩和导师" << endl;
				cin >> number >> name >> major >> score >> teacher;
				CGraduate t1(number, name, major, score, NULL, 0, teacher);
				a.add_student(&t1);
				//a.display();
				break;
			}
			case'0':
				break;
			default:
				cout << "选择错误，请重新选择" << endl;
				break;
			}
		}
	}
	void test1() {
		CStudentList a;
		char str[20];
		char name[20];
		char major[20];
		char teacher[20];
		long number;
		ifstream in2("test.dat");
		a.read_bin(in2);
		in2.close();
		CAssociation b("bzzb");
		int i;
		for (i = 0; i < a.ncount; i++) {
			b.add(a[i]);
		}
		b.show();
		ofstream out1("bzzb.txt");
		ofstream out2("bzzb.dat");
		b.write_txt(out1);
		//out1.close();
		b.write_bin(out2);
		out2.close();
		CAssociation c("ff");
		ifstream in1("bzzb.txt");
		c.read_txt(in1,a);
		c.show();
		ifstream in3("bzzb.dat");
		c.read_bin(in3,a);
		c.show();
	}
};
bool testMyStringIO()
{
	myString str("I love C++ programming!"), str2("haha");
	ofstream out("MyString.txt");
	out << str; out.close();
	ifstream in("MyString.txt"); str2.read_txt(in); in.close();
	if (strcmp(str2.get_string(), str.get_string()) != 0) return false;
	out.open("MyString.txt");
	str.write_txt(out);
	out.close(); in.open("MyString.txt"); str2.read_txt(in); in.close(); if (strcmp(str2.get_string(), str.get_string()) != 0) return false;
	out.open("MyString.dat");
	str.write_bin(out);
	out.close();
	in.open("MyString.dat");
	str2.read_bin(in);
	in.close();
	if (strcmp(str2.get_string(), str.get_string()) != 0)
		return false;
	return true;
}
int main() {
	CAPP bzzb;
	int i;
	//bzzb.run1();
	bzzb.test1();
	return 0;
}

