#include <cstdio>
#include <map>
#include <string.h>

using namespace std;

int main()
{
	char s1[81], s2[81];
	map<char, bool> hashMap;

	scanf("%s", &s1);
	scanf("%s", &s2);

	int i = 0, j = 0;
	while (j < strlen(s1))
	{
		if (s1[j] != s2[i])
		{
			if (s1[j] >= 'a' && s1[j] <= 'z')
			{
				s1[j] = s1[j] - 'a' + 'A';
			}
			if (!hashMap[s1[j]])
			{
				printf("%c", s1[j]);
				hashMap[s1[j]] = true;
			}
			j ++;
		}else
		{
			i ++;
			j ++;
		}
	}

	return 0;
}