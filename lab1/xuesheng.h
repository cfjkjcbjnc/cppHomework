#pragma once
namespace N20281272 {
	struct student {
		long number;
		char name[20];
		char major[20];
		double score;
		student* next;
	};
	
	class CStudentList {
	public:
		CStudentList();
		CStudentList(const student& stu);
		CStudentList(const CStudentList& stu);
		CStudentList& operator=(const CStudentList& stu);
		~CStudentList();
		void add_student(student stu);
		void display();
		void display(double low, double high);
		void delete_student(long number);
		student*& getByName(const char*name);
		student*& modifyScore(const char* name, double score);
	private:
		student* head_stu;
		student* tail_stu;
		int ncount;
	};
}