#include <cstdio>
#include <stdlib.h>

struct Node
{
	char s;
	int next;
	bool flag;
}node[100000];

int main() {
	Node node1, node2;
	int n;
	scanf("%d%d%d",&node1.next,&node2.next,&n);

	//Node* p = (Node*)malloc((n+1) * sizeof(Node));
	for (int i = 0; i < 100000; i++)
	{
		node[i].flag = false;
	}

	for (int i = 0; i < n; i++)
	{
		int add;
		scanf("%d ",&add);
		scanf("%c %d",&node[add].s,&node[add].next);
	}
	for (int p = node1.next; p != -1;p = node[p].next)
	{
		node[p].flag = true;
	}

	for (int p = node2.next; p != -1; p = node[p].next)
	{
		if (node[p].flag == true)
		{
			printf("%05d",p);
			return 0;
		}
	}
	printf("-1");
}