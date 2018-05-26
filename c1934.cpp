#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d",&n);

	int* p;
	p = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&p[i]);
	}

	int x;
	scanf("%d",&x);
	
	int j = 0;
	for (; p[j] != x; j++);
	if (j == n)
	{
		printf("-1");
	}else
		printf("%d",j);
}