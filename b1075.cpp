#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
	int addr;
	int data;
	int next;
}nodes[100000];

int main()
{
	int first, n, k;
	scanf("%d%d%d", &first, &n, &k);

	int addr;
	int kAddr;
	Node node;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &addr);
		nodes[addr].addr = addr;
		scanf("%d%d", &nodes[addr].data, &nodes[addr].next);
		if (nodes[addr].data == k)
		{
			kAddr = addr;
		}
	}

	vector<Node> newNodes;
	addr = first;
	while (addr != -1)
	{
		if (nodes[addr].data < 0)
			newNodes.push_back(nodes[addr]);
		addr = nodes[addr].next;
	}
	addr = first;
	while (addr != -1)
	{
		if (nodes[addr].data >= 0 && nodes[addr].data <= k)
			newNodes.push_back(nodes[addr]);
		addr = nodes[addr].next;
	}
	addr = first;
	while (addr != -1)
	{
		if (nodes[addr].data > k)
			newNodes.push_back(nodes[addr]);
		addr = nodes[addr].next;
	}

	for (int i = 0; i < newNodes.size() - 1; i++)
	{
		newNodes[i].next = newNodes[i + 1].addr;
	}
	newNodes[newNodes.size() - 1].next = -1;

	for (int i = 0; i < newNodes.size(); i++)
	{
		printf("%05d %d ", newNodes[i].addr, newNodes[i].data);
		if (i == newNodes.size() - 1)
		{
			printf("-1\n");
		}else
		{
			printf("%05d\n", newNodes[i].next);
		}
	}

}