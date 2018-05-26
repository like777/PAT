#include <stdio.h>

int main() {
	int n,t;
	int b,s,g;

	scanf("%d",&n);
	g = n % 10;
	t = n / 10;
	s = t % 10;
	t = t / 10;
	b = t % 10;

	for (int i = 0; i < b; i++)
		printf("B");
	for (int i = 0; i < s; i++)
	{
		printf("S");
	}
	for (int i = 1; i <= g; i++)
	{
		printf("%d",i);
	}
}