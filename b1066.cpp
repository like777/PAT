#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n, m, min, max, target;
	scanf("%d%d%d%d%d", &n, &m, &min, &max, &target);
	vector<vector<int>> ans(n);
	for (int i = 0; i < n; i++)
	{
		ans[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &ans[i][j]);
			if (ans[i][j] >= min && ans[i][j] <= max)
			{
				ans[i][j] = target;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			printf("%03d", ans[i][j]);
		}
		printf("\n");
	}
}