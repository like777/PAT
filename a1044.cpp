#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Ans
{
	int start, end;
};

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> numbers(n + 1);
	numbers[0] = 0;
	for (int i = 1, number; i <= n; i++)
	{
		scanf("%d", &number);
		numbers[i] = numbers[i - 1] + number;
	}

	vector<Ans> ans;
	int min_money = 100000000;
	int sum = 0;
	int temp = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = max(i + 1, temp); j < n + 1; j++)
		{
			if (numbers[j] - numbers[i] >= m)
			{
				if (numbers[j] - numbers[i] < min_money)
				{
					ans.clear();
					Ans a;
					a.start = i + 1;
					a.end = j;
					ans.push_back(a);
					min_money = numbers[j] - numbers[i];
					temp = j;
				}
				else if (numbers[j] - numbers[i] == min_money)
				{
					Ans a;
					a.start = i + 1;
					a.end = j;
					ans.push_back(a);
					temp = j;
				}
				break;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d-%d\n", ans[i].start, ans[i].end);
	}
}