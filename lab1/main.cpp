#include<iostream>
#include"xuesheng.h"
#include"mystring.h"
using namespace N20281272;
using namespace std;
int main() {
	char c='p';
	student temp;
	char str[20];
	char name[20];
	char major[20];
	long number;
	double low, high, score;
	CStudentList a;
	while (c!='0') {
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
			cout << "����������ѧ�š�������רҵ�ͳɼ�" << endl;
			cin >> number >> name >> major >> score;
			student temp(number, name, major, score, NULL);
			a.add_student(temp);
			cout << endl;
			break;
		}
		case'2':
			a.display();
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
	//test1();
	return 0;
}