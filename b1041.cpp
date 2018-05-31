#include <cstdio>
#include <cstdlib>

struct Student
{
	char id[15];
	int seat;
};

int main()
{
	int n, m;
	char tempId[15];
	int temp;
	Student* students;
	int* students_to_find;

	scanf("%d", &n);
	students = (Student*)malloc((n + 1) * sizeof(Student));

	for (int i = 1; i < n + 1; i++)
	{
		scanf("%s %d", tempId, &temp);
		scanf("%d", &students[temp].seat);
		for (int j = 0; j < 15; j++)
		{
			students[temp].id[j] = tempId[j];
		}
	}

	scanf("%d", &m);
	students_to_find = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++)
	{
		scanf("%d",students_to_find + i);
	}

	for (int i = 0; i < m; i++)
	{
		printf("%s %d\n", students[students_to_find[i]].id, students[students_to_find[i]].seat);
	}
}