#include <stdio.h>
#include <string.h>

int main() {
	long a,b,c;
	int d,x;
	int n[100];
	int i = 0;
	scanf("%ld%ld%d",&a,&b,&d);

	c = a + b;
	x = c;
	for (; x > 0; i++)
	{
		n[i] = x % d;
		x = x / d;
	}
	if (c == 0)
	{
		printf("0");
	}else
	{
	    for (int j = i - 1; j >= 0; j--)
	    {
		    printf("%d",n[j]);
	    }
	}

}