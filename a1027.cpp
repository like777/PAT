#include <cstdio>

void print(int n)
{
	if (n > 9)
	{
		printf("%c", n - 10 + 'A');
	}else
	{
		printf("%d", n);
	}
}

int main()
{
	int n[3];
	scanf("%d%d%d", n, n + 1, n + 2);

	printf("#");

	for (int i = 0; i < 3; i++)
	{
		print(n[i] / 13);
		print(n[i] % 13);
	}

	return 0;
}