#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	int k1, k2;
	map<int, double> numbers;

	scanf("%d", &k1);
	int n;
	double a = 0;
	for (int i = 0; i < k1; i++)
	{
		scanf("%d%lf", &n, &a);
		numbers[n] += a;
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++)
	{
		scanf("%d%lf", &n, &a);
		numbers[n] += a;
	}
	int count = 0;
	for (map<int, double>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it)
	{
		if (it -> second != 0.0 && it ->second != -0.0)
		{
			++count;
		}
	}
	printf("%d", count);

	for (map<int, double>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it)
	{
		if (it -> second == 0.0 || it -> second == -0.0)
		{
			continue;
		}
		printf(" %d %.1f", (*it).first, (*it).second);
	}
}