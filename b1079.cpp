#include <iostream>
#include <vector>
#include <string>

using namespace std;

string add(string s1, string s2)
{
	string s;
	int c = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] + s2[i] - '0' * 2 + c >= 10)
		{
			s.push_back(s1[i] + s2[i] + c - '0' - 10);
			c = 1;
		}else
		{
			s.push_back(s1[i] + s2[i] + c - '0');
			c = 0;
		}
	}
	if (c > 0)
	{
		s.push_back('1');
	}
	return s;
}

string change(string s)
{
	string s1;
	for (int i = 0; i < s.size(); i++)
	{
		s1.push_back(s[s.size() - 1 - i]);
	}
	return s1;
}

int main()
{
	string a;
	cin >> a;

	if (change(a) == a)
	{
		cout << a << " is a palindromic number.";
		return 0;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			cout << a << " + " << change(a) << " = " << change(add(change(a),a)) << endl;
		}else
			cout << change(a) << " + " << a << " = " << change(add(change(a),a)) << endl;
		a = add(change(a), a);
		if (a == change(a))
		{
			cout << a << " is a palindromic number.";
			break;
		}
		if (i == 9)
		{
			printf("Not found in 10 iterations.");
		}
	}
}