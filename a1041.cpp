#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int number;
	vector<int> vec;
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		++mp[number];
		vec.push_back(number);
	}

	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (mp[vec[i]] == 1)
		{
			printf("%d", vec[i]);
			return 0;
		}
	}
	printf("None");

}