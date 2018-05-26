#include <stdio.h>
#include <stdlib.h>
#include <cmath>

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int N,sum = 0;
	int j = 0;
	int *p;

	scanf("%d",&N);
	p = (int*)malloc(N*sizeof(int));
	for (int i = 2; i <= N; i++)
	{
		if (isPrime(i) == true)
		{
			p[j] = i;
			if (j > 0)
			{
				if (p[j] - p[j - 1] == 2)
				{
					sum ++;
				}
			}
			j ++;
		}
	}

	printf("%d",sum);
}