#include <cstdio>

int func(int a, int b) {
	if (a > b)
	{
		return func(a - b, b);
	}
	else if (a < b)
	{
		return func(a, b - a);
	}else
	{
		return a;
	}
}

int main() {
	int a, b;
	scanf("%d%d",&a,&b);
	printf("%d",func(a,b));
}