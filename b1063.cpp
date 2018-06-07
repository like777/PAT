#include <cstdio>
#include <cmath>

int main()
{
	double max = 0;
	double a, b;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &a, &b);
		if (sqrt(a * a + b * b) > max)
		{
			max = sqrt(a * a + b * b);
		}
	}
	printf("%.2f", max);
}