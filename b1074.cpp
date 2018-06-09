#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
	int c = 0;
	vector<int> n1;
	vector<int> n2;
	vector<int> n;
	vector<int> ans;
	string s, s1, s2;
	cin >> s >> s1 >> s2;

	for (int i = s.size() - 1; i > -1; i--)
	{
		if (s[i] == '0')
		{
			n.push_back(10);
		}else
		{
			n.push_back(s[i] - '0');
		}
	}
	n.push_back(10);

	for (int i = s1.size() - 1; i > -1; i--)
	{
		n1.push_back(s1[i] - '0');
	}

	for (int i = s2.size() - 1; i > -1; i--)
	{
		n2.push_back(s2[i] - '0');
	}

	while (n1.size() < n2.size())
	{
		n1.push_back(0);
	}
	while (n1.size() > n2.size())
	{
		n2.push_back(0);
	}

	for (int i = 0; i < n1.size(); i++)
	{
		if (n1[i] + n2[i] + c >= n[i])
		{
			ans.push_back(n1[i] + n2[i] + c - n[i]);
			c = 1;
		}else
		{
			ans.push_back(n1[i] + n2[i] + c);
			c = 0;
		}
	}
	if (c > 0)
	{
		ans.push_back(1);
	}

	bool flag = false;
	for (int i = 0; i < ans.size(); i++)
	{
		if (!flag && ans[ans.size() - i - 1] == 0)
		{
			continue;
		}else
		{
			printf("%d", ans[ans.size() - i - 1]);
			flag = true;
		}
	}
	flag = false;
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] != 0)
		{
			flag = true;
		}
	}
	if (flag = false)
	{
		printf("0");
	}
}