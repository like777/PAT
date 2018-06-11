#include <cstdio>
#include <cstring>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	a = a + b;

	if (a == 0)
	{
		printf("0");
		return 0;
	}
	char str[1000010];
	bool minus = false;
	if (a < 0)
	{
		minus = true;
		a = -a;
	}
	int k = 0;
	for (int i = 1; a > 0; i++)
	{
		str[k++] = a % 10 + '0';
		a = a / 10;
		if (i % 3 == 0 && a > 0)
		{
			str[k++] = ',';
		}
	}
	str[k] = '\0';
	if (minus)
	{
		printf("-");
	}
	for (int i = strlen(str) - 1; i >= 0; --i)
	{

		printf("%c", str[i]);
	}
}