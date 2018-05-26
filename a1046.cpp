#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);

	int *d = new int[n];

	int temp = 0;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&temp);
		d[i] = sum + temp;
		sum = d[i];
	}

	int m;
	scanf("%d",&m);

	for (int i = 0; i < n; i++)
	{
		int p1, p2;
		int sum1 = 0, sum2 = 0;
		scanf("%d%d", &p1, &p2);
		sum1 =(d[(p2 + n - 2) % n] + sum - d[(p1 + n - 2) % n]) % sum;
		sum2 = sum - sum1;
		if (sum1 < sum2)
		{
			printf("%d\n",sum1);
		}else
		{
			printf("%d\n",sum2);
		}
	}
}

//因遍历次数过多超时
/**
#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);

	int *d = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d",d + i);
	}

	int m;
	scanf("%d",&m);

	for (int i = 0; i < m; i++)
	{
		int p1, p2;
		scanf("%d%d",&p1,&p2);

		int sum1 = 0, sum2 = 0;

		for (int j = p1 + n - 1; j % n != p2 - 1; j++)
		{
			sum1 = sum1 + d[j % n];
		}

		for (int j = p1 + n - 2; (j % n) != ((p2 + n - 2) % n); j--)
		{
			sum2 = sum2 + d[j % n];
		}
		if (sum1 > sum2)
		{
			printf("%d\n",sum2);
		}
		else
		{
			printf("%d\n",sum1);
		}
	}
}
**/