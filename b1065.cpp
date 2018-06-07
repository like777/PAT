#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	int member1, member2, member;
	int couples[100000];
	vector<int> single;
	bool map[100000] = {false};
	memset(couples, 0xff, sizeof(couples));

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &member1, &member2);
		couples[member1] = member2;
		couples[member2] = member1;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &member);
		map[member] = true;
		single.push_back(member);
	}
	
	for (int i = 0; i < single.size(); i++)
	{
		if (couples[single[i]] != -1 && map[couples[single[i]]])
		{
			single.erase(single.begin() + i);
			--i;
		}
	}
	sort(single.begin(), single.end());
	printf("%d\n", single.size());
	for (int i = 0; i < single.size(); i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%05d", single[i]);
	}
}