#include <iostream>
#include <string>

using namespace std;

int main()
{
	char ch;
	cin >> ch;

	string s;
	getline(cin, s);
	if (ch == 'C')
	{
		getline(cin, s);
		char character = '!';
		int sum = 1;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == character)
			{
				sum ++;
			}
			else if (character != '!')
			{
				if (sum > 1)
				{
					cout << sum;
					sum = 1;
				}
				cout << character;
			}
			character = s[i];
		}
		if (sum > 1)
		{
			cout << sum;
			sum = 1;
		}
		cout << character;
	}else
	{
		getline(cin, s);
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				sum = sum * 10 + s[i] - '0';
				++i;
			}
			if (sum == 0)
			{
				cout << s[i];
			}else
			{
				for (int j = 0; j < sum; j++)
				{
					cout << s[i];
				}
				sum = 0;
			}
		}
	}
	cout << endl;

}