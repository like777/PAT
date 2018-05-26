#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct Student
{
	char registration_number[13];
	int score;
	int location_number;
	int local_rank;
	int final_rank;
};

bool cmp(struct Student a, Student b) {
	if (a.score != b.score)
	{
		return a.score > b.score;
	}else
	{
		return strcmp(a.registration_number,b.registration_number) < 0;
	}
}

int main() {
	int n;
	int* k;
	scanf("%d",&n);
	k = (int*)malloc(n*sizeof(int));

	struct Student s[100][300];

	for (int i = 0; i < n; i ++)
	{
		scanf("%d",&k[i]);
		for (int j = 0; j < k[i]; j++)
		{
			scanf("%s%d",&s[i][j].registration_number,&s[i][j].score);
		}
	}

	for (int i = 0; i < n; i ++)
	{
		sort(&s[i][0],&s[i][k[i]],cmp);
		for (int j = 0; j < k[i]; j++)
		{
			if (j > 0 && s[i][j].score == s[i][j-1].score)
			{
				s[i][j].local_rank = s[i][j-1].local_rank;
			}else
			{
				s[i][j].local_rank = j + 1;
			}
			s[i][j].location_number = i + 1;
		}
	}

	int totalNum = 0;

	for (int i = 0; i < n; i++)
	{
		totalNum += k[i];
	}
	printf("%d\n",totalNum);

	struct Student* t;
	t = (Student*)malloc((totalNum + 1)*sizeof(Student));
	for (int i = 0, m = 0; i < n; i++)
	{
		for (int j = 0; j < k[i]; j++)
		{
			t[m] = s[i][j];
			m++;
		}
	}
	free(k);
	sort(&t[0],&t[totalNum],cmp);
	for (int i = 0; i < totalNum; i++)
	{
		if (i > 0 && t[i].score == t[i-1].score)
		{
			t[i].final_rank = t[i-1].final_rank;
		}else
		{
			t[i].final_rank = i + 1;
		}
	}
	for (int i = 0; i < totalNum; i++)
	{
		printf("%s %d %d %d\n",t[i].registration_number,t[i].final_rank,t[i].location_number,t[i].local_rank);
	}
}