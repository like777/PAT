#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);

	int asum = 0, bsum = 0;
	int a1, a2, b1, b2;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&a1, &a2, &b1, &b2);
		if (a1 + b1 == a2 && a1 + b1 != b2)
		{
			bsum ++;
		}
		else if (a1 + b1 != a2 && a1 + b1 == b2)
		{
			asum ++;
		}
	}
	printf("%d %d", asum, bsum);
	return 0;
}