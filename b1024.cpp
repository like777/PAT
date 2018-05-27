#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	string s;
	cin >> s;

	bool isPostive;
	if (s[0] == '+')
	{
		isPostive = true;
	}else
	{
		isPostive = false;
	}

	string number;
	int i = 1;
	for (; s[i] != 'E'; i++)
	{
		if (s[i] != '.')
		{
			number.push_back(s[i]);
		}
	}
	
	bool isPowPostive;
	if (s[++i] == '+')
	{
		isPowPostive = true;
	}else
	{
		isPowPostive = false;
	}

	int pow = 0;
	for (++i; i < s.size(); i++)
	{
		pow = pow * 10 + (s[i] - '0');
	}

	if (!isPowPostive)
	{
		number.insert(number.begin(),'.');
		number.insert(number.begin(),'0');
		for (int j = 1; j < pow; j++)
		{
			number.insert(number.begin() + 2, '0');
		}
	}else
	{
		if (pow > number.size() - 1)
		{
			int length = pow + 1 - number.size();
			for (int j = 0; j < length; j++)
			{
				number.insert(number.end(), '0');
			}
		}
		else if (pow < number.size() - 1)
		{
			number.insert(number.begin() + pow + 1, '.');
		}
	}

	if (!isPostive)
	{
		cout << "-";
	}

	cout << number;
	system("pause");
	return 0;
}