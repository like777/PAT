#include <stdio.h>

struct Student
{
	char name[11];
	char num[11];
	int score;
};

int main() {
	int n;
	scanf("%d",&n);
	struct Student student[1000];
//	struct Student temp;
	for (int i = 0; i < n; i++)
		scanf("%s%s%d",&student[i].name,&student[i].num,&student[i].score);

	int max=0, min=0;
	for (int i = 0; i < n; i++)
	{
		if (student[i].score < student[min].score)
			min = i;
		if (student[i].score > student[max].score)
			max = i;
	}
	printf("%s %s\n%s %s",student[max].name,student[max].num,student[min].name,student[min].num);
	/*
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (student[j].score < student[j+1].score)
			{
				temp = student[j];
				student[j] = student[j+1];
				student[j+1] = temp;
			}
		}
	}
	printf("%s %s\n%s %s",student[0].name,student[0].num,student[n-1].name,student[n-1].num);
	*/
}