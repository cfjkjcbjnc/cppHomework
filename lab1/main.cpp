#include<iostream>
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
			case'0':
				break;
			default:
				cout << "ѡ�����������ѡ��" << endl;
				break;
			}
		}
	}
};

int main() {
	CAPP bzzb;
	//bzzb.run1();
	//test1();
	myString s1("hello "), s2("world!");
	const myString s3 = s1 + s2; //����s3����Ϊ"hello world!"������s1��s2����
	s1 = s1 + "world!";   //����s1������Ϊ"hello world!"
	cout << s1[0] << s3[1] << endl;//���Ϊ"he"
	s1("I love C++, yeah!");   //����s1����Ϊ"I love C++, yeah!"
	return 0;
}

