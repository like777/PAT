#include <cstdio>
#include <cmath>

int main()
{
	int n, minPeople, maxPeople;
	double min = 200, max = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int number, x, y;
		scanf("%d%d%d", &number, &x, &y);
		if (sqrt((double)(x * x) + (double)(y * y)) > max )
		{
			max = sqrt((double)(x * x) + (double)(y * y));
			maxPeople = number;
		}
		if (sqrt((double)(x * x) + (double)(y * y)) < min )
		{
			min = sqrt((double)(x * x) + (double)(y * y));
			minPeople = number;
		}
	}
	printf("%04d %04d", minPeople, maxPeople);
}