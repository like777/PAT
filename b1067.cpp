#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(string s1, string s2)
{
	if (s1 != s2)
		return false;
	return true;
}

int main()
{
	string correct;
	string s;
	int n;
	int times = 0;
	vector<string> ans;
	//scanf("%s %d", correct, &n);
	cin >> correct >> n;
	getline(cin, s);

	for (int i = 0; ; i++)
	{
		//scanf("%s", s);
		getline(cin, s);
		++times;
		if (times <= n)
		{
			if (s == "#")
			{
				//ans.push_back("try again");
				break;
			}
			else if (s == correct)
			{
				ans.push_back("Welcome in");
				break;
			}
			else
			{
				ans.push_back("Wrong password: " + s);
			}
		}else
		{
			ans.push_back("Account locked");
			break;
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}