#include <cstdio>

int main()
{
	int n;
	int number, id = 0;
	int numbers[37] = {0};
	int ans[37] = {0};
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		while (number != 0)
		{
			id += number % 10;
			number /= 10;
		}
		numbers[id] = 1;
		id = 0;
	}
	int j = 0;
	for (int i = 0; i < 37; i++)
	{
		if (numbers[i] != 0)
		{
			ans[j] = i;
			++j;
		}
	}
	printf("%d\n", j);
	for (int i = 0; i < j; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", ans[i]);
	}
}