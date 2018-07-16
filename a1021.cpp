#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node
{
	int key;
	vector<int> children;
}nodes[10010];

int main()
{
	int n;
	scanf("%d", &n);

	int temp1, temp2;
	while (scanf("%d%d", &temp1, &temp2) != EOF)
	{
		nodes[temp1].key = temp1;
		nodes[temp2].key = temp2;
		nodes[temp1].children.push_back(temp2);
		nodes[temp2].children.push_back(temp1);
	}
	
	bool error = false;
	int c = 0;
	queue<int> que;
	map<int, bool> m;
	que.push(1);
	while (1)
	{
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (m[i] == false)
			{
				flag++;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}
		flag = 0;
		while (!que.empty())
		{
			for (int j = 0; j < nodes[que.front()].children.size(); j++)
			{
				if (m[que.front()] == false)
				{
					que.push(nodes[que.front()].children[j]);
				}else
				{
					error = true;
				}
			}
			m[que.front()] = true;
			que.pop();
		}
	}

}