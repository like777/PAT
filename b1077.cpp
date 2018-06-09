#include <cstdio>


using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int g, g1, g2;
	for (int i = 0; i < n; i++)
	{
		int people = 0;
		int sum = 0;
		int min = m, max = 0;
		scanf("%d", &g1);
		for (int j = 0; j < n - 1; j++)
		{
			scanf("%d", &g);
			if (g >= 0 && g <= m)
			{
				if (g < min)
				{
					min = g;
				}
				if (g > max)
				{
					max = g;
				}
				sum += g;
				++people;
			}
		}
		printf("%d\n", (g1 + (sum - max - min) / (people - 2) + 1) / 2);

	}
}