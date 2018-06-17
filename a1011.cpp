#include <cstdio>

int main()
{
	double games[3][3];
	double max[3] = {0, 0, 0};
	char name[3];
	char map[3] = {'W', 'T', 'L'};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%lf", &games[i][j]);
			if (games[i][j] > max[i])
			{
				max[i] = games[i][j];
				name[i] = map[j];
			}
		}
	}
	printf("%c %c %c %.2f", name[0], name[1], name[2], max[0] * max[1] * max[2] * 0.65 * 2 - 2);

}