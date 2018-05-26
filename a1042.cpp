#include <cstdio>

#define total 54


int main() {
	int n;
	scanf("%d",&n);

	int s[54];
	int t[54];
	int u[54];

	for (int i = 0; i < total; i++)
	{
		s[i] = i;
	}

	for (int i = 0; i < total; i++)
	{
		scanf("%d",t + i);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < total; j++)
		{
			u[t[j] - 1] = s[j];
		}
		for (int k = 0; k < total; k++)
		{
			s[k] = u[k];
		}
	}

	for (int i = 0; i < total; i++)
	{
		if (i < total - 1) 
		{
			if (u[i] < 13)
				printf("S%d ",u[i] + 1);
			else if (u[i] < 26)
				printf("H%d ",u[i] - 12);
			else if (u[i] < 39)
				printf("C%d ",u[i] - 25);
			else if (u[i] < 52)
				printf("D%d ",u[i] - 38);
			else
			{
				printf("J%d ",u[i] - 51);
			}
		}else
		{
			if (u[i] < 13)
				printf("S%d",u[i] + 1);
			else if (u[i] < 26)
				printf("H%d",u[i] - 12);
			else if (u[i] < 39)
				printf("C%d",u[i] - 25);
			else if (u[i] < 52)
				printf("D%d",u[i] - 38);
			else
			{
				printf("J%d",u[i] - 51);
			}
		}

	}
}