#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


int main() 
{
	int sum;
	int n;
	char c;

	scanf("%d %c", &sum, &c);
	n = (int) sqrt((sum + 1) / 2);

	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < n - i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}

	printf("%d", sum - 2 * n * n + 1);

	return 0;
}