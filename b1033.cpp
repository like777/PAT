/*一分的测试点结果出错：原因：用了cin输入 
    如果没有坏键的话，用cin取不到这种情况
    改用gets   
    cin>>errs;
    cin>>s;
 */

#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main()
{
	char s1[100010], s2[100010];

	map<char, bool> hashMap;
	bool upKey = false;

	int i = 0;
	while ((s1[i] = getchar()) != '\n')
	{
		i ++;
	}


	i = 0;
	while ((s2[i] = getchar()) != '\n')
	{
		i ++;
	}

	for (i = 0; s1[i] != '\n'; i++)
	{
		if (s1[i] >= 'a' && s1[i] <= 'z')
			hashMap[s1[i] - 'a' + 'A'] = true;
		else
			hashMap[s1[i]] = true;
		if (s1[i] == '+')
		{
			upKey = true;
		}
	}

	for (i = 0; s2[i] != '\n'; i++)
	{
		if (s2[i] >= 'a' && s2[i] <= 'z' && hashMap[s2[i] - 'a' + 'A'])
		{
			continue;
		}
		else if (upKey && s2[i] >= 'A' && s2[i] <= 'Z')
		{
			continue;
		}
		else if (hashMap[s2[i]])
		{
			continue;
		}

		printf("%c",s2[i]);
	}
	return 0;

}