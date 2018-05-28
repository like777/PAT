#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
	long long p;
	scanf("%d%d", &n, &p);
	long long temp;
	int max = 0;

	vector<long long> numbers;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());

	for (int i = 0, j = 0; i < n && j < n; i++)
	{
		while (j < n && numbers[j] <= numbers[i] * p)
		{
			j ++;
		}
		if (j - i > max)
		{
			max = j - i;
		}
	}
	printf("%d", max);
	return 0;
}