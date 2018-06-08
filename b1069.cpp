#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	int m, n, s;
	vector<string> people;
	vector<string> winners;
	map<string, bool> check;
	string str;
	cin >> m >> n >> s;

	if (s > m)
	{
		cout << "Keep going...";
		return 0;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		cin >> str;
		people.push_back(str);
		if (j + 1 >= s && (j + 1) % n == s % n)
		{
			if (check[str] == false)
			{
				check[str] = true;
				winners.push_back(str);
				++j;
			}
		}else
		{
			++j;
		}
	}

	//for (int i = 0; i < people.size(); i++)
	//{
	//	if (i + 1 >= s && (i + 1) % n == s % n)
	//	{
	//		if (check[people[i]] == false)
	//		{
	//			check[people[i]] = true;
	//			winners.push_back(people[i]);
	//			++i;
	//		}else
	//		{
	//			int j = 1;
	//			while (check[people[i + j]])
	//				++j;
	//			winners.push_back(people[i + j]);
	//		}
	//	}
	//}

		
	for (int i = 0; i < winners.size(); i++)
	{
		cout << winners[i] << endl;
	}

	//if (winners.size() == 0)
	//{
	//	cout << "Keep going...";
	//}
}