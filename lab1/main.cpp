#include<iostream>
#include<fstream>
#include"xuesheng.h"
#include"mystring.h"
using namespace N20281272;
using namespace std;
class CAPP {
public:
	void run1() {
		char c = 'p';
		student temp;
		char str[20];
		char name[20];
		char major[20];
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
				a.add_student(temp);
				b.add(a.get(number));
				b.show();
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
			}
			case'7':
			{
			//	ifstream in1("test.txt");
			//	a.read_txt(in1);
			//	in1.close();
				ifstream in2("test.dat");
				a.read_bin(in2);
				in2.close();
			}
			case'0':
				break;
			default:
				cout << "ѡ�����������ѡ��" << endl;
				break;
			}
		}
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
	bzzb.run1();
	//if (testMyStringIO())cout << "MyString IO OK" << endl; else cout << "MyString IO failed" << endl;
	return 0;
}

