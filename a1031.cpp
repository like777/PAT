#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < (str.size() + 2) / 3 - 1; i++)
	{
		printf("%c", str[i]);
		for (int j = 0; j < str.size() - 2 * (int)((str.size() + 2) / 3); j++)
		{
			printf(" ");
		}
		printf("%c\n", str[str.size() - i - 1]);
	}

	for (int i = (str.size() + 2) / 3 - 1; i < str.size() - (int)(str.size() + 2) / 3 + 1; i++)
	{
		printf("%c", str[i]);
	}

}