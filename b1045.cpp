//当答案数为0时需要输出两个\n！！！！
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	long long number;
	long long left = 0;
	long long right = 0;
	vector<long long> numbers;
	set<long long> order;
	set<long long> ans;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &number);
		numbers.push_back(number);
		order.insert(number);
	}
	left = numbers[0];

	for (int i = 0; i < n; i++)
	{
		right = *order.begin();
		if (numbers[i] >= left && numbers[i] <= right)
		{
			ans.insert(numbers[i]);
		}
		if (numbers[i] > left)
		{
			left = numbers[i];
		}
		order.erase(order.find(numbers[i]));

	}

	if (!ans.size())
	{
		printf("0\n");
	}else
	{
		printf("%d\n", ans.size());
		for (set<long long>::iterator it = ans.begin(); it != ans.end(); it ++)
		{
			if (it == ans.begin())
			{
				printf("%lld", *it);
			}else
			{
				printf(" %lld", *it);
			}
	
		}

	}
}