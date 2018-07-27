#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Student
{
	int id;
	char name[9];
	int grade;
};

bool cmp1(Student a, Student b)
{
	return a.id < b.id;
}

bool cmp2(Student a, Student b)
{
	for (int i = 0; ; i++)
	{
		if (a.name[i] == '\0' && b.name[i] == '\0')
		{
			return a.id < b.id;
		}
		if (a.name[i] == '\0')
		{
			return true;
		}
		if (b.name[i] == '\0')
		{
			return false;
		}
		if (a.name[i] != b.name[i])
		{
			return a.name[i] < b.name[i];
		}
	}
}

bool cmp3(Student a, Student b)
{
	if (a.grade != b.grade)
	{
		return a.grade < b.grade;
	}
	return a.id < b.id;
}

int main()
{
	int n, c;
	scanf("%d%d", &n, &c);

	vector<Student> students(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %d", &students[i].id, &students[i].name, &students[i].grade);
	}

	switch (c)
	{
	case 1:
		sort(students.begin(), students.end(), cmp1);
		break;
	case 2:
		sort(students.begin(), students.end(), cmp2);
		break;
	case 3:
		sort(students.begin(), students.end(), cmp3);
		break;
	}

	for (int i = 0; i < students.size(); i++)
	{
		printf("%06d %s %d\n", students[i].id, students[i].name, students[i].grade);
	}
}