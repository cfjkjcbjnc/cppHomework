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
		cout << "学生信息管理系统" << endl;
		cout << "1 录入学生信息" << endl;
		cout << "2 显示学生信息" << endl;
		cout << "3 删除学生信息" << endl;
		cout << "4 显示某一成绩范围的学生信息" << endl;
		cout << "5 测试复制构造函数" << endl;
		cout << "6 测试有参数的构造函数" << endl;
		cout << "7 通过名字更改学生成绩" << endl;
		cout << "8 测试赋值运算符" << endl;
		cout << "0 退出系统" << endl;
		cout << "请选择操作" << endl;
		cin >> c;
		switch (c) {
		case'1':
			cout << "请依次输入学号、姓名、专业和成绩" << endl;
			cin >> s.number >> s.name >> s.major >> s.score;
			a.add_student(s);
			cout << endl;
			break;
		case'2':
			a.display();
			cout << endl;
			break;
		case'3':
			cout << "请输入要删除的学生学号" << endl;
			cin >> s.number;
			a.delete_student(s.number);
			cout << endl;
			break;
		case'4':
			cout << "请依次输入区间的最小值和最大值" << endl;
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
			cout << "依次输入名字,成绩" << endl;
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
			cout << "选择错误，请重新选择" << endl;
			break;
		}
	}
}