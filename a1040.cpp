#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int max = 1;
	for (int i = 1; i < str.size(); i++)
	{
		int max1 = 1;
		for (int j = 1; i - j >= 0 && i + j < str.size(); j++)
		{
			if (str[i - j] == str[i + j])
			{
				max1 += 2;
			}else
			{
				break;
			}
		}
		if (max1 > max)
		{
			max = max1;
		}
	}

	for (int i = 0; i < str.size() - 1; i++)
	{
		int max2 = 0;
		for (int j = 0; i - j >= 0 && i + j + 1 < str.size(); j++)
		{
			if (str[i - j] == str[i + j + 1])
			{
				max2 += 2;
			}else
			{
				break;
			}
		}
		if (max2 > max)
		{
			max = max2;
		}
	}
	printf("%d", max);
}