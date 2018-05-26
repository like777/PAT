#include<cstdio>
#include<algorithm>

using namespace std;


int main() 
{
	int n[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%d",&n[i]);
	}

	if(n[0] != 0) {
		int m = 1;
		for (; n[m] == 0; m++);
		printf("%d",m);
		n[m] = n[m] - 1;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}