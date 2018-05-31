#include<iostream>
#include<string>

using namespace std;

int main()
{
	int map[128] = {0};
	int max = 0;
	int maxMark = 127;
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			++map[s[i] - 'A' + 'a'];
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			++map[s[i]];
		}
	}

	for (int i = 0; i < 128; i++)
	{
		if (map[i] > max)
		{
			max = map[i];
			maxMark = i;
		}
		else if (map[i] == max)
		{
			if (i < maxMark)
			{
				maxMark = i;
			}
		}
	}

	cout << (char)maxMark << " " << max;


}