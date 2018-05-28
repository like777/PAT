#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char b[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool judge(string s)
{
	int sum = 0;
	for (int i = 0; i < 17; i++)
	{
		if (s[i] > '9' || s[i] < '0')
		{
			return false;
		}
		sum += (s[i] - '0') * a[i];
	}
	if (b[sum % 11] != s[17])
	{
		return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;

	vector<string> idNumbers;
	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (!judge(s))
		{
			idNumbers.push_back(s);
		}
	}
	if (idNumbers.size() == 0)
	{
		cout << "All passed";
	}else
	{
		for (int i = 0; i < idNumbers.size(); i++)
		{
			cout << idNumbers[i] << endl;
		}
	}

	return 0;
}