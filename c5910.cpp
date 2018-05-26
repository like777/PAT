#include <stdio.h>
#include <string>

bool check(char s[]) {
	for (int i = 0; i < strlen(s) / 2; i++)
	{
		if (s[i] != s[strlen(s) - 1 - i])
		{
			return false;
		}
	}
	return true;

}

int main() {
	char s[256];
	gets(s);

	if (check(s) == true)
	{
		printf("YES");
	}else
	{
		printf("NO");
	}
}