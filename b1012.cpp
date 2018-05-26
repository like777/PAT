#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);
	
	int a1[1000] = {0}, a2[1000] = {0}, a3[1000] = {0}, a4[1000] = {0}, a5[1000] = {0};
	int aa1 = 0, aa2 = 0, aa3 = 0, aa4 = 0, aa5 = 0;
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d",&m);

		switch (m % 5)
		{
		case 0:
			a1[i1] = m;
			++ i1;
			break;
		case 1:
			a2[i2] = m;
			++ i2;
			break;
		case 2:
			a3[i3] = m;
			++ i3;
			break;
		case 3:
			a4[i4] = m;
			++ i4;
			break;
		case 4:
			a5[i5] = m;
			++ i5;
			break;
		default:
			break;
		}
	}
	if (i1 == 0)
	{
		printf("N ");
	}else
	{
		for (int i = 0; i < i1; i++)
		{
			if (a1[i] % 2 == 0)
			{
				aa1 += a1[i];
			}
		}
		if (aa1 == 0)
		{
			printf("N ");
		}else
		{
			printf("%d ",aa1);
		}
	}
	if (i2 == 0)
	{
		printf("N ");
	}else
	{
		for (int i = 0; i < i2; i++)
		{
			if (i % 2 == 0)
			{
				aa2 += a2[i];
			}else
			{
				aa2 -= a2[i];
			}
		}
		printf("%d ",aa2);
	}
	if (i3 == 0)
	{
		printf("N ");
	}else
	{
		printf("%d ",i3);
	}
	if (i4 == 0)
	{
		printf("N ");
	}else
	{
		for (int i = 0; i < i4; i++)
		{
			aa4 += a4[i];
		}
		printf("%.1f ",(double)aa4 / i4);
	}
	if (i5 == 0)
	{
		printf("N");
	}else
	{
		for (int i = 0; i < i5; i++)
		{
			if (aa5 < a5[i])
			{
				aa5 = a5[i];
			}
		}
		printf("%d",aa5);
	}
}