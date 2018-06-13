#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int number;
	int temp = 0, time = 5 * n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		if (number > temp)
			time += 6 * (number - temp);
		else if (number < temp)
			time += 4 * (temp - number);
		temp = number;
	}
	printf("%d", time);
}