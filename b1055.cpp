#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct People
{
	char name[9];
	int height;
};

bool cmp(People people1, People people2)
{
	if (people1.height != people2.height)
		return people1.height > people2.height;
	else
	{
		for (int i = 0; i < strlen(people1.name) || i < strlen(people2.name); i++)
		{
			if (people1.name[i] == '\0')
			{
				return true;
			}
			else if (people2.name[i] == '\0')
			{
				return false;
			}
			else if (people1.name[i] != people2.name[i])
			{
				return people1.name[i] < people2.name[i];
			}
		}
	}
}

int main()
{
	int n;
	int k;
	int lastQ, q;
	People people;
	vector<People> peoples;
	vector<People> line;
	scanf("%d%d", &n, &k);

	q = n / k;
	lastQ = n - (n / k) * k + n / k;

	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", &people.name, &people.height);
		peoples.push_back(people);
	}
	sort(peoples.begin(), peoples.end(), cmp);

	vector<People>::iterator it = peoples.begin();
	for (int i = 0; i < lastQ; i++)
	{
		if (i % 2 == 0)
			line.push_back(*it);
		else
			line.insert(line.begin(),*it);
		++ it;
	}
	printf("%s", line[0].name);
	for (int i = 1; i < lastQ; i++)
	{
		printf(" %s", line[i].name);
	}
	printf("\n");

	if (k > n)
	{
		return 0;
	}
	for (int i = 0; i < k - 1; i++)
	{
		line.clear();
		for (int j = 0; j < q; j++)
		{
			if (j % 2 == 0)
				line.push_back(*it);
			else
				line.insert(line.begin(), *it);
			++it;
		}
		printf("%s", line[0].name);
		for (int i = 1; i < q; i++)
		{
			printf(" %s", line[i].name);
		}
		printf("\n");
	}
	return 0;
}