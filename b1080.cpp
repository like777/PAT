#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

struct Student
{
	char name[21];
	int program, middleTest, finalTest, total;
}students[30010];

bool cmp (Student student1, Student student2)
{
	if (student1.total == student2.total)
	{
		return strcmp(student1.name, student2.name) < 0;
	}
	return student1.total > student2.total;
}

int main()
{
	int p, m, n;
	scanf("%d%d%d", &p, &m, &n);

	map<string, int> studentsNumber;
	int c = 0;
	char id[21];
	int grade;
	for (int i = 0; i < p; i++)
	{
		scanf("%s %d", id, &grade);
		if (studentsNumber[id] == 0 && grade >= 200)
		{
			studentsNumber[id] = ++c;
			strcpy(students[studentsNumber[id]].name, id);
			students[studentsNumber[id]].program = grade;
			students[studentsNumber[id]].middleTest = -1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s %d", id, &grade);
		if (studentsNumber[id] == 0)
			continue;
		strcpy(students[studentsNumber[id]].name, id);
		students[studentsNumber[id]].middleTest = grade;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", id, &grade);
		if (studentsNumber[id] == 0)
			continue;
		students[studentsNumber[id]].finalTest = grade;
		strcpy(students[studentsNumber[id]].name, id);
		if (students[studentsNumber[id]].middleTest > students[studentsNumber[id]].finalTest)
			students[studentsNumber[id]].total = students[studentsNumber[id]].middleTest * 0.4 + students[studentsNumber[id]].finalTest * 0.6 + 0.5;
		else
			students[studentsNumber[id]].total = students[studentsNumber[id]].finalTest;
	}

	sort(students + 1, students + c + 1, cmp);

	for (int i = 1; i <= c; i++)
	{
		if (students[i].total >= 60)
		{
			printf("%s %d %d %d %d\n", students[i].name, students[i].program, students[i].middleTest, students[i].finalTest, students[i].total);
		}
	}
}