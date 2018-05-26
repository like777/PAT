#include <cstdio>
#include <cmath>

using namespace std;

struct List
{
	int key;
	int next;
	bool flag;
}list[100010];

int main() {
	int n;
	scanf("%d%d",&list[100000].next, &n);

	bool hash[100010] = {false};

	for (int i = 0, addr = 0; i < n; i++)
	{
		scanf("%d", &addr);
		scanf("%d%d",&list[addr].key, &list[addr].next);

	}
	int temp = list[100000].next;
	while (temp != -1)
	{
		if (hash[abs(list[temp].key)])
		{
			list[temp].flag = true;
		}else
		{
			list[temp].flag = false;
			hash[abs(list[temp].key)] = true;
		}
		temp = list[temp].next;
	}

	int pre1, pre2;
	pre1 = 100000;
	pre2 = 100001;
	temp = list[100000].next;

	while (temp != -1)
	{
		if (list[temp].flag)
		{
			list[pre1].next = list[temp].next;
			list[pre2].next = temp;
			pre2 = temp;
			
		}else
		{
			pre1 = temp;
		}
		temp = list[temp].next;
	}
	
	pre1 = 100000;
	temp = list[100000].next;
	while (temp != -1)
	{
		if (list[temp].next == -1)
		{
			printf("%05d %d -1\n", temp, list[temp].key);
		}else
		{
			printf("%05d %d %05d\n", temp, list[temp].key, list[temp].next);
		}
		pre1 = temp;
		temp = list[temp].next;
	}

	pre2 = 100001;
	temp = list[100001].next;
	while (temp != -1)
	{
		if (list[temp].next == -1)
		{
			printf("%05d %d -1\n", temp, list[temp].key);
		}else
		{
			printf("%05d %d %05d\n", temp, list[temp].key, list[temp].next);
		}
		pre2 = temp;
		temp = list[temp].next;
	}
}