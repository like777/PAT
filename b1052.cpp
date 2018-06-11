//n一定要判断是否小于1！！！
//最后一个测试点n输入是0！！！！
#include <iostream>
#include <string>
#include <vector>

#define emoji_part 3
#define emoji_size 5

using namespace std;

int match[5] = {0, 1, 2, 1, 0};

int main()
{
	string s;
	string temp;
	int k;
	int n;
	vector<vector<string>> parts;
	parts.resize(emoji_part);

	for (int i = 0; i < emoji_part; i++)
	{
		getline(cin, s);
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '[')
			{
				++j;
				while (s[j] != ']')
				{
					temp.push_back(s[j++]);
				}
				parts[i].push_back(temp);
				temp.clear();
			}
		}
	}


	cin >> k;
	for (int i = 0; i < k; i++)
	{
		s.clear();
		bool f = false;
		for (int j = 0, flag = 0; j < emoji_size; j++)
		{
			cin >> n;
			if (flag == 0 &&( n > parts[match[j]].size() || n < 1))
			{
				cout << "Are you kidding me? @\\/@";
				f = true;
				flag = 1;
			}
			else if (flag == 0)
			{
				s.insert(s.end(),parts[match[j]][n - 1].begin(), parts[match[j]][n - 1].end());
				if (j == 0)
				{
					s.insert(s.end(), '(');
				}
				else if (j == 3)
				{
					s.insert(s.end(), ')');
				}
			}
		}
		if (!f)
			cout << s;
		cout << endl;
	}
}
