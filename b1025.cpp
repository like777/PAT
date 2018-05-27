#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
	int address;
	int n;
	int next;
}node[100010];

int main()
{
	int first, n, k;
	int tempNow;
	vector<Node> nodes;
	Node tempNode;

	scanf("%d%d%d", &first, &n, &k);


	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tempNow);
		scanf("%d%d", &node[tempNow].n, &node[tempNow].next);
		node[tempNow].address = tempNow;
	}

	tempNow = first;
	while (tempNow != -1)
	{
		nodes.push_back(node[tempNow]);
		tempNow = node[tempNow].next;
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		if (i / k < nodes.size() / k)
		{
			if (i % k < k / 2)
			{
				tempNode = nodes[i];
				nodes[i] = nodes[i + k - (i % k) * 2 - 1];
				nodes[i + k - (i % k) * 2 - 1] = tempNode;
			}
		}
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		if (i < nodes.size() - 1)
		{
			nodes[i].next = nodes[i + 1].address;
		}else
		{
			nodes[i].next = -1;
		}
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].next != -1)
		{
			printf("%05d %d %05d\n", nodes[i].address, nodes[i].n, nodes[i].next);
		}else
		{
			printf("%05d %d -1\n", nodes[i].address, nodes[i].n);
		}
		
	}

	system("pause");
	return 0;
}





/*
#include <cstdio>

using namespace std;

struct Node
{
	int n;
	int postion;
	int prev;
	int next;
}node[100010];

int main()
{
	int first, n, k;
	scanf("%d%d%d", &first, &n, &k);

	int tempNow;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tempNow);
		scanf("%d%d", &node[tempNow].n, &node[tempNow].next);
	}
	int j = 0;
	int tempPrev = -1;
	tempNow = first;
	while(tempNow != -1)
	{
		node[tempNow].postion = j;
		node[tempNow].prev = tempPrev;
		tempPrev = tempNow;
		tempNow = node[tempNow].next;
		++j;
	}

	tempPrev = -1;
	tempNow = first;
	int tempNext;
	int temp;
	while ( node[tempNow].postion / k < (j - 1) / k)
	{
		if (node[tempNow].postion % k == 0)
		{
			tempPrev = node[tempNow].prev;
			node[tempNow].prev = node[tempNow].next;
			tempNext = tempNow;
			tempNow = node[tempNow].prev;
		}
		else if (node[tempNow].postion % k == k - 1)
		{
			node[tempNext].next = node[tempNow].next;
			node[tempNow].next = node[tempNow].prev;
			node[tempNow].prev = tempPrev;
			node[node[tempNow].prev].next = tempNow;
			if (tempPrev == -1)
			{
				first = tempNow;
			}
			tempNow = node[tempNext].next;
		}
		else 
		{
			temp = node[tempNow].next;
			node[tempNow].next = node[tempNow].prev;
			node[tempNow].prev = temp;
			tempNow = node[tempNow].prev;
		}
		
	}

	tempNow = first;
	while (tempNow != -1)
	{
		if (node[tempNow].next != -1)
		{
			printf("%05d %d %05d\n", tempNow, node[tempNow].n, node[tempNow].next);
		}else
		{
			printf("%05d %d -1\n", tempNow, node[tempNow].n);
		}
		tempNow = node[tempNow].next;
	}

	return 0;
}
*/