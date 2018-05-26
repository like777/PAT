#include<cstdio>
#include<cmath>

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main() {
	int m, n;
	int flag = 0;
	scanf("%d%d",&m,&n);

	for (int i = 2, j = 0; ; i++)
	{
		if (isPrime(i))
		{
			j ++;
		
			if (j >= m)
			{
				printf("%d",i);
				flag ++;
				if (j == n)
				{
					return 0;
				}
				else if (flag == 10)
				{
					printf("\n");
					flag = 0;
				}else
				{
					printf(" ");
				}
			}
		}
	}
}