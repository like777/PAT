#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int number;
	map<int, int> numbers;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &number);
		++numbers[abs(number - i)];
	}

	for (map<int, int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); rit++)
	{
		if ((*rit).second != 1)
		{
			printf("%d %d\n", (*rit).first, (*rit).second);
		}

	}
}