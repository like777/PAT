#include <cstdio>

int main()
{
	int n;
	double sum = 0;
	double number;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &number);
		sum += number * (i + 1) * (n - i);
	}

	printf("%.2f", sum);
}