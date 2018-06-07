#include <cstdio>
#include <cmath>

bool isPrime(int n)
{
	for (int i = 2; i <= (int)sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n, k;
	int temp;
	int competitors[10010] = {0};
	bool checked[10010] = {false};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		competitors[temp] = i + 1;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &temp);
		printf("%04d: ", temp);
		if (competitors[temp] == 0)
			printf("Are you kidding?");
		else if (checked[temp])
			printf("Checked");
		else if (competitors[temp] == 1)
			printf("Mystery Award");
		else if (isPrime(competitors[temp]))
			printf("Minion");
		else
			printf("Chocolate");
		printf("\n");
		checked[temp] = true;
	}


}