#include<iostream>
#include"xuesheng.h"
using namespace N20281272;
using namespace std;
int main() {
	char c='p';
	student s = {1,"a","a",1};
	char str[20];
	double low, high, score;
	CStudentList a;
	while (c!='0') {
		cout << "ѧ����Ϣ����ϵͳ" << endl;
		cout << "1 ¼��ѧ����Ϣ" << endl;
		cout << "2 ��ʾѧ����Ϣ" << endl;
		cout << "3 ɾ��ѧ����Ϣ" << endl;
		cout << "4 ��ʾĳһ�ɼ���Χ��ѧ����Ϣ" << endl;
		cout << "5 ���Ը��ƹ��캯��" << endl;
		cout << "6 �����в����Ĺ��캯��" << endl;
		cout << "7 ͨ�����ָ���ѧ���ɼ�" << endl;
		cout << "8 ���Ը�ֵ�����" << endl;
		cout << "0 �˳�ϵͳ" << endl;
		cout << "��ѡ�����" << endl;
		cin >> c;
		switch (c) {
		case'1':
			cout << "����������ѧ�š�������רҵ�ͳɼ�" << endl;
			cin >> s.number >> s.name >> s.major >> s.score;
			a.add_student(s);
			cout << endl;
			break;
		case'2':
			a.display();
			cout << endl;
			break;
		case'3':
			cout << "������Ҫɾ����ѧ��ѧ��" << endl;
			cin >> s.number;
			a.delete_student(s.number);
			cout << endl;
			break;
		case'4':
			cout << "�����������������Сֵ�����ֵ" << endl;
			cin >> low >> high;
			a.display(low, high);
			break;
		case'5':
		{
			CStudentList b(a);
			b.display();
			break;
		}
		case'6':
		{
			CStudentList b(s);
			b.display();
			break;
		}
		case'7':
		{
			cout << "������������,�ɼ�" << endl;
			cin >> str >> score;
			a.modifyScore(str, score);
		}
		case'8':
		{
			CStudentList c(s);
			c = a;
			c.display();
		}
		case'0':
			break;
		default:
			cout << "ѡ�����������ѡ��" << endl;
			break;
		}
	}
}