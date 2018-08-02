#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	string temp1, temp2;
	temp1 = a + b;
	temp2 = b + a;
	return temp1 < temp2;
}
int main()
{
	int n;
	cin >> n;

	vector<string> str(n);
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	sort(str.begin(), str.end(), cmp);
	string str1;
	for (int i = 0; i < n; i++)
	{
		str1 += str[i];
	}

	bool flag = false;
	for (int i = 0; i < str1.size(); i++)
	{
		if (!flag && str1[i] == '0')
		{
			continue;
		}
		cout << str1[i];
		flag = true;
	}
	if (!flag)
	{
		cout << 0;
	}
}