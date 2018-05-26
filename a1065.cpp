/*
#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
		scanf
	}

}
*/










#include <cstdio>
#include <string.h>

void change(char a[20],int b [20]) {
	int length = strlen(a);
	for (int i = 0; i < length; i++)
	{
		b[length - i - 1] = a[i] - '0';
	}
}

void add(int a[20], int b[20], int c[20]) {
	int temp = 0;
	for (int i = 0; i < 20; i++)
	{
		if (a[i] + b[i] + temp > 9)
		{
			c[i] = a[i] + b[i] + temp - 10;
			temp = 1;
		}else
		{
			c[i] = a[i] + b[i] + temp;
			temp = 0;
		}
	}
}

bool judge(int a[20], int b[20]) {
	for (int i = 19; i >= 0; i--)
	{
		if (a[i] > b[i])
		{
			return true;
		}
		else if (a[i] < b[i])
		{
			return false;
		}
	}
	return false;
}

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
		char x[20], y[20], z[20];
		int a[20] = {0}, b[20] = {0}, sum[20] = {0}, c[20] = {0};
		scanf("%s%s%s",x,y,z);
		change(x, a);
		change(y, b);
		change(z, c);
		add(a, b, sum);
		for (int j = 0; j < 20; j++)
		{
			printf("%d",sum[j]);
		}
		if (judge(sum,c))
		{
			printf("Case #%d: true\n", i + 1);
		}else
		{
			printf("Case #%d: false\n", i + 1);
		}
	}

}
