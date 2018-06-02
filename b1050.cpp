#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int N;
	int m, n;
	int number;
	vector<int> numbers;
	
	scanf("%d", &N);

	for (int i = (int)sqrt(N); i >= 1; i--)
	{
		if (N % i == 0)
		{
			n = i;
			m = N / i;
			break;
		}
	}
	vector<vector<int>> ans(m, vector<int>(n, 0));
	vector<vector<int>> flag(m, vector<int>(n, 0));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number);
		numbers.push_back(number);
	}
	sort(numbers.begin(), numbers.end(), cmp);

	int k = 0;
	int x = 0, y = 0;
	ans[x][y] = numbers[k];
	flag[x][y] = true;
	++k;
	while (k < N)
	{
		for (int j = 0; y + 1 < n && !flag[x][y + 1]; j++)
		{
			ans[x][++y] = numbers[k];
			flag[x][y] = true;
			++k;
		}
		for (int j = 0; x + 1 < m && !flag[x + 1][y]; j++)
		{
			ans[++x][y] = numbers[k];
			flag[x][y] = true;
			++k;
		}
		for (int j = 0; y - 1 >= 0 && !flag[x][y - 1]; j++)
		{
			ans[x][--y] = numbers[k];
			flag[x][y] = true;
			++k;
		}
		for (int j = 0; x - 1 >= 0 && !flag[x - 1][y]; j++)
		{
			ans[--x][y] = numbers[k];
			flag[x][y] = true;
			++k;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < n - 1)
			{
				printf("%d ", ans[i][j]);
			}else
			{
				printf("%d\n", ans[i][j]);
			}
		}
	}
}