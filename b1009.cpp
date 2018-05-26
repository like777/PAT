#include <stdio.h>
#include <string.h>

int main() {
	int n = 0;
	char p[81][81] = {0};
	char s[81];
	gets(s);
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			n++;
		}
	}

	for (int i = 0, t = 0; i <= n; i++)
	{
		for (int j = 0; s[t] != ' '&& s[t] != '\0'; j++)
		{
			p[i][j] = s[t];
			t ++;
		}
		t ++;
	}
	for (int i = n; i > 0 ; i --)
	{
		printf("%s ",p[i]);
	}
	printf("%s",p[0]);
	
}