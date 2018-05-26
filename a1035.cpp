#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Team
{
	string name;
	string password;
	bool flag;
};

int main() {
	int n;
	cin >> n;
	Team* p = new Team[n];

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].name >> p[i].password;
		p[i].flag = true;
		for (int j = 0; j < p[i].password.size(); j++)
		{
			if (p[i].password[j] == '1')
			{
				p[i].password[j] = '@';
				p[i].flag = false;
			}
			else if (p[i].password[j] == '0')
			{
				p[i].password[j] = '%';
				p[i].flag = false;
			}
			else if (p[i].password[j] == 'l')
			{
				p[i].password[j] = 'L';
				p[i].flag = false;
			}
			else if (p[i].password[j] == 'O')
			{
				p[i].password[j] = 'o';
				p[i].flag = false;
			}
		}
	}
	int t = n;
	for (int i = 0; i < n; i++)
	{
		if (p[i].flag == true)
		{
			t --;
		}
	}
	if (t == 0)
	{
		if (n == 1)
		{
			cout << "There is 1 account and no account is modified";
		}else
		{
			cout << "There are " << n << " accounts and no account is modified";
		}
		
	}else
	{
		cout << t << "\n";
		for (int i = 0; i < n; i++)
		{
			if (p[i].flag == false)
			{
				cout << p[i].name << " " << p[i].password << "\n";
			}
		}
	}
	return 0;
}