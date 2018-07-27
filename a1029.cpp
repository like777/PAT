#include<cstdio>
#include<deque>

using namespace std;

int main()
{
	int n1, n2;
	scanf("%d", &n1);

	long long number;
	deque<long long> numbers;

	for (int i = 0; i < n1; i++)
	{
		scanf("%lld", &number);
		numbers.push_back(number);
	}

	long long ans;
	int j = 0;
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		scanf("%lld", &number);
		while (j < numbers.size() && numbers[j] < number)
		{
			++j;
		}
		numbers.insert(numbers.begin() + j, number);
		if (j >= (n1 + n2 - 1) / 2)
		{
			ans = numbers[(n1 + n2 - 1) / 2];
			break;
		}
	}

	printf("%lld", ans);
	return 0;
}