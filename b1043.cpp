#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int map[127] = {0};

	for (int i = 0; i < s.size(); i++)
	{
		++map[s[i]];
	}

	while (map['P'] || map['A'] || map['T'] || map['e'] || map['s'] || map['t'])
	{
		if (map['P'])
		{
			cout << 'P';
			--map['P'];
		}
		if (map['A'])
		{
			cout << 'A';
			--map['A'];
		}
		if (map['T'])
		{
			cout << 'T';
			--map['T'];
		}
		if (map['e'])
		{
			cout << 'e';
			--map['e'];
		}
		if (map['s'])
		{
			cout << 's';
			--map['s'];
		}
		if (map['t'])
		{
			cout << 't';
			--map['t'];
		}
	}
}