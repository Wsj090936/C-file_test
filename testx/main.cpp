#include <iostream>
#include <string.h>
using namespace std;
class CStudent
{
public:
	CStudent(char *n, int a);
	~CStudent();
	int age;
private:
	char *name;

};
CStudent::CStudent(char *n, int a):age(a)
{
	int nLen = strlen(n);
	name = new char[nLen+1];
	strcpy(name,n);
	name[nLen] = '\0';
}
CStudent::~CStudent()
{
	delete[] name;
}
class CTeacher
{
public:
	CTeacher(char *tn, int ta,CStudent x);

	~CTeacher();
	void SetStuAge(int a);
private:
	char *name;
	int age;
	CStudent stu;
};
CTeacher::CTeacher(char *tn, int ta,CStudent x):age(ta),stu(x)
{
	int nLen = strlen(tn);
	name = new char[nLen+1];
	strcpy(name,tn);
	name[nLen] = '\0';
}
CTeacher::~CTeacher()
{
	delete[] name;
}
void CTeacher::SetStuAge(int a)
{
	stu.age = a;
}
int main()
{
	CStudent stu("张三",25);
	CTeacher tea("李四",26,stu);
	return 0;
}

