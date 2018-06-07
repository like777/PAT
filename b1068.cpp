//差值为绝对值
//数字必须独一无二
//边界值也要考虑！！！
#include <cstdio>
#include <vector>
#include <map>
#define director 8

using namespace std;

int xm[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ym[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
	int m, n, tol;
	int x = 0, y = 0;
	int flag = 0;
	long long temp;
	scanf("%d%d%d", &m, &n, &tol);

	vector<vector<long long>> picture(n + 2);
	map<int, int> M;

	for (int i = 0; i <= n + 1; i++)
	{
		if (i == 0 || i == n + 1)
		{
			for (int j = 0; j <= m + 1; j++)
			{
				picture[i].push_back(- tol - 1);
			}
		}else
		{
			for (int j = 0; j <= m + 1; j++)
			{
				if (j == 0 || j == m + 1)
				{
					picture[i].push_back(- tol - 1);
				}else
				{
					scanf("%lld", &temp);
					picture[i].push_back(temp);
					++M[temp];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < director; k++)
			{
				if (abs(picture[i][j] - picture[i + ym[k]][j + xm[k]]) <= tol)
				{
					break;
				}
				if (M[picture[i][j]]== 1 && k == director - 1)
				{
					x = j;
					y = i;
					++ flag;
					if (flag == 2)
						break;
				}
			}
			if (flag == 2)
				break;
		}
		if (flag == 2)
			break;
	}
	if (flag == 2)
		printf("Not Unique");
	else if (flag == 0)
		printf("Not Exist");
	else
	{
		printf("(%d, %d): %lld", x, y, picture[y][x]);
	}
}