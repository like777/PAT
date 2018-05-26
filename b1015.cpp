#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	int id;
	int morality;
	int ability;
};

bool cmp(Student a, Student b)
{
	if (a.morality + a.ability != b.morality + b.ability)
	{
		return a.morality + a.ability > b.morality + b.ability;
	}
	else
	{
		if (a.morality != b.morality)
		{
			return a.morality > b.morality;
		}
		else
		{
			return a.id < b.id;
		}
	}
	
}

int main() 
{
	int n, l, h;
	scanf("%d%d%d",&n, &l, &h);

	vector<Student> student1;
	vector<Student> student2;
	vector<Student> student3;
	vector<Student> student4;

	Student temp;

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &temp.id, &temp.morality, &temp.ability);
		if (temp.morality >= h && temp.ability >= h)
		{
			student1.push_back(temp);
		}
		else if (temp.morality >= h && temp.ability >= l)
		{
			student2.push_back(temp);
		}
		else if (temp.morality >= l && temp.ability >= l && temp.morality >= temp.ability)
		{
			student3.push_back(temp);
		}
		else if (temp.morality >= l && temp.ability >= l)
		{
			student4.push_back(temp);
		}
	}

	sort(student1.begin(), student1.end(), cmp);
	sort(student2.begin(), student2.end(), cmp);
	sort(student3.begin(), student3.end(), cmp);
	sort(student4.begin(), student4.end(), cmp);

	printf("%d\n",student1.size() + student2.size() + student3.size() + student4.size());

	for (int i = 0; i < student1.size(); i++)
	{
		printf("%d %d %d\n",student1[i].id, student1[i].morality, student1[i].ability);
	}
	for (int i = 0; i < student2.size(); i++)
	{
		printf("%d %d %d\n",student2[i].id, student2[i].morality, student2[i].ability);
	}
	for (int i = 0; i < student3.size(); i++)
	{
		printf("%d %d %d\n",student3[i].id, student3[i].morality, student3[i].ability);
	}
	for (int i = 0; i < student4.size(); i++)
	{
		printf("%d %d %d\n",student4[i].id, student4[i].morality, student4[i].ability);
	}

	return 0;
}