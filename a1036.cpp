#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
	string name;
	char gender;
	string id;
	int grade;
};

int main()
{
	int n;
	scanf("%d", &n);

	vector<Student> students;
	Student student;
	for (int i = 0; i < n; i++)
	{
		cin >> student.name >> student.gender >> student.id >> student.grade;
		students.push_back(student);
	}

	int max_grade = -1, min_grade = 101, f = -1, m = -1;
	for (int i = 0; i < n; i++)
	{
		if (students[i].gender == 'M')
		{
			if (students[i].grade < min_grade)
			{
				m = i;
				min_grade = students[i].grade;
			}
		}else
		{
			if (students[i].grade > max_grade)
			{
				f = i;
				max_grade = students[i].grade;
			}
		}
	}

	if (f > -1)
	{
		cout << students[f].name << " " << students[f].id << endl;
	}else
	{
		printf("Absent\n");
	}

	if (m > -1)
	{
		cout << students[m].name << " " << students[m].id << endl;
	}else
	{
		printf("Absent\n");
	}

	if (m == -1 || f == -1)
	{
		printf("NA\n");
	}else
	{
		printf("%d\n",students[f].grade - students[m].grade);
	}
}