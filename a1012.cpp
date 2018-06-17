#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

char Map[4] = {'A', 'C', 'M', 'E'};
int flag = -1;
struct Student
{
	int id, grade[4];
	int rank[4];
};

bool cmp(Student student1, Student student2)
{
	return student1.grade[flag] > student2.grade[flag];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	map<int, Student> students;
	vector<Student> vecStudents;
	Student student;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &student.id, &student.grade[1], &student.grade[2], &student.grade[3]);
		student.grade[0] = (student.grade[1] + student.grade[2] + student.grade[3]) / 3 + 0.5;
		students[student.id] = student;
		vecStudents.push_back(student);
	}

	for (flag = 0; flag < 4; ++flag)
	{
		sort(vecStudents.begin(), vecStudents.end(), cmp);
		for (int i = 0; i < students.size(); i++)
		{
			if (i == 0)
				students[vecStudents[i].id].rank[flag] = 1;
			else if (students[vecStudents[i].id].grade[flag] == students[vecStudents[i - 1].id].grade[flag])
				students[vecStudents[i].id].rank[flag] = students[vecStudents[i - 1].id].rank[flag];
			else
				students[vecStudents[i].id].rank[flag] = i + 1;
		}
	}

	int id;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &id);
		if (students[id].id == 0)
		{
			printf("N/A\n");
			continue;
		}
		int min = students[id].rank[0];
		int course = 0;
		for (int j = 1; j < 4; j++)
		{
			if(students[id].rank[j] < min)
			{
				min = students[id].rank[j];
				course = j;
			}
		}
		printf("%d %c\n", min, Map[course]);
	}

}