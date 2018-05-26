#include <cstdio>
#include <string.h>

int main() {
	char a[11], b[11];
	char da, db;
	int flaga = 0, flagb = 0;
	int pa = 0, pb = 0;
	scanf("%s %c %s %c",a, &da, b, &db);

	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == da)
			flaga ++;
	}

	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == db)
		{
			flagb ++;
		}
	}

	for (int i = 0; i < flaga; i++)
	{
		pa = pa * 10 + da - '0';
	}

	for (int i = 0; i < flagb; i++)
	{
		pb = pb * 10 + db - '0';
	}
	printf("%d",pa + pb);
	return 0;
}