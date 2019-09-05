#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct student
{
	string first;
	string last;
	int id;
	int test1;
	int test2;
	int test3;
	int test4;
	int test5;
	double average;
	char grade;
};
int main()
{
	student stu[8];
	fstream grade;
	grade.open("grade.dat");
	for (int i = 0; i < 8; i++)
	{
		string temp;
		grade >> temp;
		stu[i].first = temp;
		string temp1;
		grade >> temp1;
		stu[i].last = temp1;
		int temp2;
		grade >> temp2;
		stu[i].id = temp2;
		grade >> stu[i].test1;
		grade >> stu[i].test2;
		grade >> stu[i].test3;
		grade >> stu[i].test4;
		grade >> stu[i].test5;


	}
	grade.close();
	for (int j = 0; j < 8; j++)
	{
		cout << "hello" << stu[j].id;
		
	}
}