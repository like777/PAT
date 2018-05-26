#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool IsPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

typedef struct PrimeFactors
{
	int number;
	int m;
};

int main() {
	int n;
	scanf("%d",&n);
	int t = n;
	int p = 0;

	PrimeFactors primefactors[11];

	fill(&primefactors[0].m,&primefactors[10].m,0);

	for (int i = 2; i <= sqrt(t); i++)
	{
		if (IsPrime(i))
		{
			if (t % i == 0)
			{
				primefactors[p].number = i;
				primefactors[p].m ++;
				t = t / i;
				while (t % i == 0)
				{
					primefactors[p].m ++;
					t = t / i;
				}
				p ++;
			}

		}
	}

	if (t != 1)
	{
		primefactors[p].number = t;
		primefactors[p].m ++;
		p ++;
	}

	if (n == 1)
	{
		printf("1=1");
		return 0;
	}

	printf("%d=",n);
	for (int i = 0; i < p - 1; i++)
	{
		if (primefactors[i].m == 1)
		{
			printf("%d*",primefactors[i].number);
		}else
		{
			printf("%d^%d*",primefactors[i].number,primefactors[i].m);
		}
	}
	if (primefactors[p - 1].m == 1)
		{
			printf("%d",primefactors[p - 1].number);
		}else
		{
			printf("%d^%d",primefactors[p - 1].number,primefactors[p - 1].m);
		}
}