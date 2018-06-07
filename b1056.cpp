#include <cstdio>

using namespace std;

int main()
{
	int n, number;
	int ans = 0;
	int x = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		ans += number * (n - 1) * 11;
	}

	printf("%d", ans);
}