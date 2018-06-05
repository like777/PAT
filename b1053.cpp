#include <cstdio>

int main()
{
	int n, d;
	double e;
	int days;
	double ele;
	int eledays = 0;
	int maybeEmpty = 0;
	int empty = 0;
	scanf("%d%lf%d", &n, &e, &d);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &days);
		for (int j = 0; j < days; j++)
		{
			scanf("%lf", &ele);
			if (ele < e)
				++eledays;
		}
		if (double(eledays) / (double)days > 0.5)
		{
			if (days > d)
				++empty;
			else
				++maybeEmpty;
		}
		eledays = 0;
	}
	printf("%.1f%% %.1f%%", (double)maybeEmpty / (double)n * 100, (double)empty / (double)n * 100);

}