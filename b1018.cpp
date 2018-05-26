#include <cstdio>

int max(int a, int b, int c) {
	int maxn = 0;
	if (maxn < a)
	{
		maxn = a;
	}
	if (maxn < b)
	{
		maxn = b;
	}
	if (maxn < c)
	{
		maxn = c;
	}
	return maxn;
}

int com (char c1, char c2) {
	if (c1 == 'C' && c2 == 'J')
	{
		return 1;
	}
	else if (c1 == 'J' && c2 == 'B')
	{
		return 2;
	}
	else if (c1 =='B' && c2 == 'C')
	{
		return 3;
	}
	else if (c2 == 'C' && c1 == 'J')
	{
		return -1;
	}
	else if (c2 == 'J' && c1 == 'B')
	{
		return -2;
	}
	else if (c2 =='B' && c1 == 'C')
	{
		return -3;
	}
	else
	{
		return 0;
	}

}

int main() {
	int n;
	scanf("%d\n",&n);

	char n1, n2;
	int w1 = 0, w2 = 0;
	int j1 = 0, j2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
		{
			scanf("%c %c\n",&n1,&n2);
		}else
		{
			scanf("%c %c",&n1,&n2);
		}
		switch (com(n1, n2))
		{
		case 1:
			++ w1;
			++ c1;
			break;
		case 2:
			++ w1;
			++ j1;
			break;
		case 3:
			++ w1;
			++ b1;
			break;
		case -1:
			++ w2;
			++ c2;
			break;
		case -2:
			++ w2;
			++ j2;
			break;
		case -3:
			++ w2;
			++ b2;
		default:
			break;
		}
	}
	printf("%d %d %d\n",w1, n - w1 - w2, w2);
	printf("%d %d %d\n",w2, n - w1 - w2, w1);
	
	if (max(j1, b1, c1) == b1)
	{
		printf("B ");
	}
	else if (max(j1, b1, c1) == c1)
	{
		printf("C ");
	}else
	{
		printf("J ");
	}
	if (max(j2, b2, c2) == b2)
	{
		printf("B");
	}
	else if (max(j2, b2, c2) ==c2)
	{
		printf("C");
	}else
	{
		printf("J");
	}
}