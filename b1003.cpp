#include <stdio.h>
#include <string.h>

bool judge(char s[100]) {

	int pNum = 0, tNum = 0;
	int pPos = -1, tPos = -1;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] !='P' && s[i] != 'A'&& s[i] != 'T')
		{
			return false;
		}
		else if (s[i] == 'P')
		{
			pNum ++;
			pPos = i;
		}
		else if (s[i] == 'T')
		{
			tNum ++;
			tPos = i;
		}
	}
	if (pNum != 1 || tNum != 1)
		return false;
	else if (tPos - pPos ==1)
		return false;
	else if ((double)((strlen(s)-tPos-1))/((double)(tPos-pPos-1))!=((double)(pPos)))
	{
		return false;
	}
	return true;
}

int main() {
	char s[100];
	int n;
	bool m[10] = {0};
	scanf("%d\n",&n);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		m[i] = judge(s);
	}
	for (int i = 0; i < n; i++)
	{
		if (m[i] == true)
		{
			printf("YES");
		}else
		{
			printf("NO");
		}
		if (i != n-1)
		{
			printf("\n");
		}
	}
}