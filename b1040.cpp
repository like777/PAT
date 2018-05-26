#include<cstdio>
#include<string.h>

int main() {
	char s[100001];
	bool p[100000] = {false};
	bool a[100000] = {false};
	bool t[100000] = {false};
	gets(s);
	int sum = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == 'P')
		{
			p[i] = true;
		}
		else if (s[i] == 'A')
		{
			a[i] = true;
		}else
		{
			t[i] = true;
		}
	}

	for (int i = 0; i < strlen(s); i++)
	{
		if (p[i])
		{
			for (int j = i + 1; j < strlen(s); j++)
			{
				if (a[j])
				{
					for (int k = j + 1; k < strlen(s); k++)
					{
						if (t[k])
						{
							sum = (sum + 1) % 10000000007;
						}
					}
				}
			}
		}

	}
	printf("%d",sum);

}