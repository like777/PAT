#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int id;
	char c;
	string str, keyword;
	vector<map<string, int>> mp(5);
	vector<int> count(5);
	vector<vector<vector<int>>> vec(5);
	for (int i = 0; i < 5; i++)
	{
		vec[i].resize(1);
	}
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &id);
		getline(cin, str);
		for (int j = 0; j < 5; j++)
		{
			getline(cin, str);
			if (j != 2)
			{
				if (mp[j][str] == 0)
				{
					mp[j][str] = ++count[j];
					vec[j].push_back(temp);
				}
				vec[j][mp[j][str]].push_back(id);
			}else
			{
				for (int k = 0; k < str.size(); k++)
				{
					keyword.clear();
					while (str[k] != ' ' && k < str.size())
					{
						keyword.push_back(str[k]);
						++k;
					}
					if (mp[j][keyword] == 0)
					{
						mp[j][keyword] = ++count[j];
						vec[j].push_back(temp);
					}
					vec[j][mp[j][keyword]].push_back(id);
				}
			}
		}
	}

	int m, number;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d: ", &number);
		getline(cin, str);
		printf("%d: ", number);
		--number;
		cout << str << endl;
		if (mp[number][str] == 0)
		{
			printf("Not Found\n");
		}else
		{
			sort(vec[number][mp[number][str]].begin(), vec[number][mp[number][str]].end());
			for (int j = 0; j < vec[number][mp[number][str]].size(); j++)
			{
				printf("%07d\n", vec[number][mp[number][str]][j]);
			}
		}
	}

}