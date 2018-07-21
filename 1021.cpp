#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

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

	if (n == 1)
	{
		printf("1");
		return 0;
	}

	int temp1, temp2;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &temp1, &temp2);
		nodes[temp1].key = temp1;
		nodes[temp2].key = temp2;
		nodes[temp1].children.push_back(temp2);
		nodes[temp2].children.push_back(temp1);
	}

	bool flag = true;       //if it is a tree
	int count = 1;			//number of components
	map<int, bool> mp;
	queue<int> que;
	que.push(1);
	mp[1] = true;
	while (1)
	{
		while (!que.empty())
		{
			for (int i = 0; i < nodes[que.front()].children.size(); i++)
			{
				if (!mp[nodes[que.front()].children[i]])
				{
					que.push(nodes[que.front()].children[i]);
					mp[nodes[que.front()].children[i]] = true;
				}
			}
			que.pop();
		}
		if (mp.size() == n)
		{
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			if (mp[i] == false)
			{
				que.push(i);
				mp[i] = true;
				++count;
				flag = false;
				break;
			}
		}
	}
	if (!flag)
	{
		printf("Error: %d components", count);
		return 0;
	}

	int maxDepth = 0, tempDepth = 0;
	vector<int> tempVec;
	map<int, int> depth;
	map<int, bool> mp2;
	for (int i = 1; i < n; i++)
	{
		mp.clear();
		depth.clear();
		que.push(i);
		depth[i] = 0;
		mp[i] = true;
		while (!que.empty())
		{
			tempDepth = 0;
			tempVec.clear();
			for (int j = 0; j < nodes[que.front()].children.size(); j++)
			{
				if (!mp[nodes[que.front()].children[j]])
				{
					que.push(nodes[que.front()].children[j]);
					tempDepth = depth[nodes[que.front()].children[j]] = depth[que.front()] + 1;
					mp[nodes[que.front()].children[j]] = true;
					tempVec.push_back(nodes[que.front()].children[j]);
				}
			}
			if (tempDepth > maxDepth)
			{
				mp2.clear();
				mp2[i] = true;
				maxDepth = tempDepth;
				for (int j = 0; j < tempVec.size(); j++)
				{
					mp2[tempVec[j]] = true;
				}
			}
			else if (tempDepth == maxDepth)
			{
				mp2[i] = true;
				for (int j = 0; j < tempVec.size(); j++)
				{
					mp2[tempVec[j]] = true;
				}
			}
			que.pop();
		}

	}

	for (map<int, bool>::iterator it = mp2.begin(); it != mp2.end(); ++it)
	{
		printf("%d\n", *it);
	}
}