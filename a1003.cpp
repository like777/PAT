//DFS 深度遍历
#include <cstdio>
#include <memory.h>

int n, m, current1, current2;
int rescueNumber[510];
int distance[510][510];
int currentDistance = 0;
int minDistance = 1;
int pathNumber;
int map[510];
int maxRescue;

void cmpMap(int map[510])
{
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (map[i] > 0)
			p += rescueNumber[i];
	}
	if (p > maxRescue)
	{
		maxRescue = p;
	}
}

void DFS(int from, int to, int currentDistance)
{
	if (currentDistance > minDistance)
	{
		return;
	}
	if (to == from)
	{
		if (currentDistance < minDistance)
		{
			minDistance = currentDistance;
			pathNumber = 0;
			maxRescue = 0;
		}
		cmpMap(map);
		++pathNumber;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (map[i] > 0)
		{
			continue;
		}
		if (distance[from][i] != 0)
		{
			++map[i];
			DFS(i, to, currentDistance + distance[from][i]);
			--map[i];
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &current1, &current2);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", rescueNumber + i);
	}

	int c1, c2, l;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &c1, &c2, &l);
		distance[c1][c2] = l;
		distance[c2][c1] = l;
		minDistance += l;
	}
	map[current1] = 1;
	DFS(current1, current2, 0);
	printf("%d %d", pathNumber, maxRescue);
}
