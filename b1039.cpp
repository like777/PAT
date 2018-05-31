#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s1, s2;
	int hashMap[128] = {0};
	cin >> s1 >> s2;
	int lack = 0;
	int more = s1.size();
	for (int i = 0; i < s1.size(); i++)
	{
		++hashMap[s1[i]];
	}

	for (int i = 0; i < s2.size(); i++)
	{
		if (hashMap[s2[i]])
		{
			--hashMap[s2[i]];
			--more;
		}else
		{
			++lack;
		}
	}

	if (lack)
	{
		printf("No %d", lack);
	}else
	{
		printf("Yes %d", more);
	}
}