#include <cstdio>
#include <cstdlib>

int main()
{
	int n;
	int k;
	int temp;
	int grades[101] = {0};
	int* grades_to_find;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		++grades[temp];
	}

	scanf("%d", &k);
	grades_to_find = (int*)malloc(k * sizeof(int));

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &temp);
		grades_to_find[i] = temp;
	}

	printf("%d", grades[grades_to_find[0]]);
	for (int i = 1; i < k; i++)
	{
		printf(" %d", grades[grades_to_find[i]]);
	}
}