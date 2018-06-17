#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vector<vector<bool>> cities(n);
	for (int i = 0; i < n; i++)
		cities[i].resize(n);
	vector<vector<bool>> cities2;
	cities2 = cities;

	for (int i = 0, city1, city2; i < m; i++)
	{
		scanf("%d%d", &city1, &city2);
		cities[city1 - 1][city2 - 1] = true;
		cities[city2 - 1][city1 - 1] = true;
	}

	map<int, bool> checked;
	queue<int> q;
	for (int i = 0, city, temp; i < k; i++)
	{
		int ans = 0;
		checked.clear();
		scanf("%d", &city);
		checked[city - 1] = true;
		cities2 = cities;
		for (int j = 0; j < n; j++)
		{
			cities2[city - 1][j] = false;
		}
		if (city != 1)
		{
			q.push(0);
			checked[0] = true;
		}else
		{
			q.push(1);
			checked[1] = true;
		}

		while (!q.empty())
		{
			for (int j = 0; j < n; j++)
			{
				if (cities2[q.front()][j] && checked[j] == false)
				{
					q.push(j);
					checked[j] = true;
				}
			}
			temp = q.front();
			q.pop();
			if (q.empty())
			{
				if (checked.size() == n)
				{
					printf("%d\n", ans);
					break;
				}else
				{
					int k = 0;
					while (checked[k])
						++k;
					cities2[temp][k] = true;
					cities2[k][temp] = true;
					++ans;
					q.push(k);
					checked[k] = true;
				}
			}
		}
	}
}