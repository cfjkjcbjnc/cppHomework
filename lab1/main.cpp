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
			cout << "ѧ����Ϣ����ϵͳ" << endl;
			cout << "1 ¼��ѧ����Ϣ" << endl;
			cout << "2 ��ʾѧ����Ϣ" << endl;
			cout << "3 ɾ��ѧ����Ϣ" << endl;
			cout << "4 ��ʾĳһ�ɼ���Χ��ѧ����Ϣ" << endl;
			cout << "5 ͨ�����ָ���ѧ���ɼ�" << endl;
			cout << "6 ��ѧ����Ϣд���ļ�" << endl;
			cout << "7 ���ļ���ѧ����Ϣ����" << endl;
			cout << "8 ¼���о�����Ϣ" << endl;
			cout << "0 �˳�ϵͳ" << endl;
			cout << "��ѡ�����" << endl;
			cin >> c;
			switch (c) {
			case'1':
			{
				CAssociation b("bzzb");
				cout << "����������ѧ�š�������רҵ�ͳɼ�" << endl;
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
				cout << "������Ҫɾ����ѧ��ѧ��" << endl;
				cin >> number;
				a.delete_student(number);
				cout << endl;
				break;
			case'4':
				cout << "�����������������Сֵ�����ֵ" << endl;
				cin >> low >> high;
				a.display(low, high);
				break;
			case'5':
			{
				cout << "������������,�ɼ�" << endl;
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
				cout << "����������ѧ�š�������רҵ���ɼ��͵�ʦ" << endl;
				cin >> number >> name >> major >> score >> teacher;
				CGraduate t1(number, name, major, score, NULL, 0, teacher);
				a.add_student(&t1);
				//a.display();
				break;
			}
			case'0':
				break;
			default:
				cout << "ѡ�����������ѡ��" << endl;
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

