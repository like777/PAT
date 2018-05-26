#include <cstdio>

struct List
{
	int key;
	int next;
}list[100010];

int main() {
	int n;
	struct List first;
	scanf("%d%d",&n, &first.next);

	for (int i = 0; i < n; i++)
	{
		int add;
		scanf("%d", &add);
		scanf("%d%d", &list[add].key, &list[add].next);
	}

	for (int i = n - 2; i >= 0; i--)
	{
		int temp = first.next;
		if (list[temp].key > list[list[temp].next].key)
		{
			first.next = list[temp].next;
			list[temp].next = list[list[temp].next].next;
			list[first.next].next = temp;
		}
		int pre = temp;
		temp = list[temp].next;
		for (int j = 0; j  < i - 1; j ++)
		{
			if (list[temp].key > list[list[temp].next].key)
			{
				list[pre].next = list[temp].next;
				list[temp].next = list[list[temp].next].next;
				list[list[pre].next].next = temp;
			}
			pre = temp;
			temp = list[temp].next;
		}
	}

	printf("%d %d\n", n, first.next);
	for (int i = 0, pre = 0; i < n; i++)
	{
		static int temp = first.next;
		if (list[temp].next == -1)
		{
			printf("%05d %d %d\n",temp, list[temp].key, list[temp].next);
		}else
		{
			printf("%05d %d %05d\n",temp, list[temp].key, list[temp].next);
		}
		pre = temp;
		temp = list[temp].next;
	}
}