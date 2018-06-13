//广度优先算法 BFS
//遍历树
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int nodes[100][100] = {0};
	
	for (int i = 0; i < m; i++)
	{
		int id, k;
		scanf("%d%d", &id, &k);
		int temp;
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &temp);
			nodes[id][j] = temp;
		}
	}

	queue<int> q;
	q.push(01);
	int sum = 0;
	vector<int> ans;
	if (nodes[q.front()][0] == 0)
	{
		++sum;
	}
	ans.push_back(sum);
	sum = 0;
	int temp = 01;
	bool flag = false;
	while (!q.empty())
	{
		int k = 0;
		while (nodes[q.front()][k] != 0)
		{
			if (flag == false)
			{
				temp = nodes[q.front()][k];
				flag = true;
			}
			q.push(nodes[q.front()][k]);
			if (nodes[nodes[q.front()][k]][0] == 0)
			{
				++sum;
			}
			++k;
		}
		q.pop();
		if (q.empty())
		{
			ans.push_back(sum);
		}
		else if (q.front() == temp)
		{
			flag = false;
			ans.push_back(sum);
			sum = 0;
		}
	}

	for (int i = 0; i < ans.size() - 1; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", ans[i]);
	}
}