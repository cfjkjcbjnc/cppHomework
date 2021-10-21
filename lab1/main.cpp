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
		cout << "学生信息管理系统" << endl;
		cout << "1 录入学生信息" << endl;
		cout << "2 显示学生信息" << endl;
		cout << "3 删除学生信息" << endl;
		cout << "4 显示某一成绩范围的学生信息" << endl;
		cout << "5 通过名字更改学生成绩" << endl;
		cout << "0 退出系统" << endl;
		cout << "请选择操作" << endl;
		cin >> c;
		switch (c) {
		case'1': 
		{
			cout << "请依次输入学号、姓名、专业和成绩" << endl;
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
		case'0':
			break;
		default:
			cout << "选择错误，请重新选择" << endl;
			break;
		}
	}
	//test1();
	return 0;
}