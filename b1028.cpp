#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct People
{
	char name[6];
	int year;
	int month;
	int day;
};

bool judge(People a)
{
	if (a.year < 1814 || a.year > 2014)
	{
		return false;
	}
	else if (a.year == 1814 && a.month < 9 || a.year == 2014 && a.month > 9)
	{
		return false;
	}
	else if (a.year == 1814 && a.month == 9 && a.day < 6)
	{
		return false;
	}
	else if (a.year == 2014 && a.month == 9 && a.day > 6)
	{
		return false;
	}
	return true;
}

bool cmp(People a, People b)
{
	if (a.year < b.year)
	{
		return true;
	}
	else if (a.year > b.year)
	{
		return false;
	}
	else
	{
		if (a.month < b.month)
		{
			return true;
		}
		else if (a.month > b.month)
		{
			return false;
		}
		else
		{
			if (a.day < b.day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int main() 
{
	int n;
	People temp;
	int max = 0, min = 0;
	vector<People> people;

	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
		char tmp;
		scanf("%s %d/%d/%d", &temp.name, &temp.year, &temp.month, &temp.day);
		//cin >> temp.name >> temp.year >> tmp >> temp.month >> tmp >> temp.day;
		if (judge(temp))
		{
			people.push_back(temp);
		}
	}
	if (!people.size())
	{
		printf("0");
		/*cout << '0';*/
		return 0;
	}

	for (int i = 0; i < people.size(); i++)
	{
		if (cmp(people[i], people[max]))
		{
			max = i;
		}
		else if (cmp(people[min],people[i]))
		{
			min = i;
		}
	}
	printf("%d %s %s", people.size(), people[max].name, people[min].name);
	//cout << people.size() << " " << people[max].name << " " << people[min].name;

	//system("pause");
	return 0;
}