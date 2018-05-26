#include <stdio.h>
#include <string.h>


int main() {
	int count;
	int n[100];
	int t[100];
	int p[100];
	int s = 0;
	int temp;
	bool m[100];
	
	scanf("%d",&count);
	memset(m,true,sizeof(char)*count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d",&n[i]);
		t[i] = n[i];
	}

	for (int i = 0; i < count; i++)
	{
		while (m[i] == true && t[i] != 1)
		{
			if (t[i] % 2 ==0)
				t[i] = t[i] / 2;
			else
				t[i] = (3 * t[i] + 1) / 2;

			for (int j = 0; j < count; j++)
		    {
			    if (t[i] == n[j])
			    	m[j] = false;
		    }
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (m[i] == true) {
			p[s] = n[i];
			s++;
		}
	}

	for (int i = s - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (p[j] < p[j+1])
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	for (int i = 0; i < s-1; i++)
	{
		printf("%d ",p[i]);
	}
	printf("%d",p[s-1]);
}