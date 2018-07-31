#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct People
{
	string name;
	vector<int> contact_people;
	int totol_time;
	int group;
};

struct Answer
{
	string name;
	int people_count;
};

bool cmp(Answer a, Answer b)
{
	return a.name < b.name;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	string name1, name2;
	int time, count = 0, group_count = 0;
	map<string, int> mp;
	People people;
	vector<People> peoples(1);
	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2;
		scanf("%d", &time);
		if (mp[name1] == 0)
		{
			mp[name1] = ++count;
			people.name = name1;
			people.totol_time = time;
			peoples.push_back(people);
		}else
		{
			peoples[mp[name1]].totol_time += time;
		}
		if (mp[name2] == 0)
		{
			mp[name2] = ++count;
			people.name = name2;
			people.totol_time = time;
			people.contact_people.push_back(mp[name1]);
			peoples.push_back(people);
		}else
		{
			peoples[mp[name2]].totol_time += time;
		}
		peoples[mp[name1]].contact_people.push_back(mp[name2]);
		peoples[mp[name2]].contact_people.push_back(mp[name1]);
		peoples[mp[name1]].group = peoples[mp[name2]].group = 0;
	}

	count = 0;
	queue <int> que;
	vector<vector<People>> groups(1);
	vector<People> temp;
	for (int i = 1; i < peoples.size(); i++)
	{
		if (peoples[i].group == 0)
		{
			groups.push_back(temp);
			peoples[i].group = ++count;
			groups[count].push_back(peoples[i]);
			que.push(i);
			while (!que.empty())
			{
				for (int j = 0; j < peoples[que.front()].contact_people.size(); j++)
				{
					if (peoples[peoples[que.front()].contact_people[j]].group == 0)
					{
						que.push(peoples[que.front()].contact_people[j]);
						peoples[peoples[que.front()].contact_people[j]].group = count;
						groups[count].push_back(peoples[peoples[que.front()].contact_people[j]]);
					}

				}
				que.pop();
			}
		}
	}

	vector<Answer> vec;
	Answer answer;
	int totol_time, max_number;
	string head;
	for (int i = 1; i < groups.size(); i++)
	{
		totol_time = 0;
		max_number = 0;
		if (groups[i].size() >= 3)
		{
			for (int j = 0; j < groups[i].size(); j++)
			{
				totol_time += groups[i][j].totol_time;
				if (groups[i][j].totol_time > max_number)
				{
					max_number = groups[i][j].totol_time;
					head = groups[i][j].name;
				}
			}
			if (totol_time / 2 > k)
			{
				answer.name = head;
				answer.people_count = groups[i].size();
				vec.push_back(answer);
			}
		}
	}

	sort(vec.begin(), vec.end(), cmp);
	printf("%d\n", vec.size());
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].name;
		printf(" %d\n", vec[i].people_count);
	}



}