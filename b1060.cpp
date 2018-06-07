#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, e = 0;
	int number;
	vector<int> numbers;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		numbers.push_back(number);
	}
	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < n; i++)
	{
		if (numbers.size() - i < numbers[i])
		{
			e = numbers.size() - i;
			break;
		}
	}
	printf("%d", e);
}