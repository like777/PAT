#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct Mooncake
{
	double quantity;
	double totalPrice;
	double singlePrice;
};

bool cmp(Mooncake a,Mooncake b) {
	return a.singlePrice > b.singlePrice;
}

int main() {
	int n;
	double d;
	scanf("%d%lf",&n,&d);

	Mooncake* mooncake;
	mooncake = (Mooncake*)malloc(n*sizeof(Mooncake));

	for (int i = 0; i < n; i++)
	{
		scanf("%lf",&mooncake[i].quantity);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lf",&mooncake[i].totalPrice);
		mooncake[i].singlePrice = mooncake[i].totalPrice / mooncake[i].quantity;
	}
	sort(mooncake,mooncake+n,cmp);

	int j = 0;
	for (; d > mooncake[j].quantity; j++)
	{
		d = d - mooncake[j].quantity;
		if(j == n)
			break;
	}

	double profit = 0;
	for (int i = 0; i < j; i++)
	{
		profit = profit + mooncake[i].totalPrice;
	}
	profit = profit + mooncake[j].singlePrice * d;

	printf("%.2f\n",profit);

	free(mooncake);
	return 0;
}