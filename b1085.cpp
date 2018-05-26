#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct School
{
	//char name[6];
	string name;
	int score;
	int stuNum;
};

struct Student
{
	//char num[6];
	string num;
	int score;
	//char school[6];
	string school;
};

bool cmp(School a, School b) {
	if (a.score == b.score)
	{
		if (a.stuNum == b.stuNum)
		{
			//return (strcmp(a.name,b.name) == -1);
			return a.name < b.name;
		}

		return a.stuNum < b.stuNum;
	}
	return a.score > b.score;
}

int main() {
	int n;
	scanf("%d",&n);
	vector<Student> student(n);
	vector<School> school;
	map<string,bool> flag;

	for (int i = 0; i < n; i++)
	{
		//scanf("%s %d %s", &student[i].num, &student[i].score, &student[i].school);
		cin >> student[i].num >> student[i].score >> student[i].school;

		//for (int j = 0; j < strlen(student[i].school); j++)
		for (int j = 0; j < student[i].school.size(); j++)
		{
			if ((student[i].school)[j] >= 'A' && student[i].school[j] <= 'Z')
			{
				student[i].school[j] -= ('A' - 'a');
			}
		}
		int j = 0;
		//for (; j < school.size(); j++)
		//{
		//	//if (strcmp(student[i].school,school[j].name) == 0)
		//	if (student[i].school == school[j].name)
		if (flag[student[i].school] == true)
			{
				if (student[i].num[0] == 'A')
					school[j].score += student[i].score;
				else if (student[i].num[0] == 'T')
					school[j].score += student[i].score * 1.5;
				else
					school[j].score += student[i].score / 1.5;
				++ school[j].stuNum;
				//break;
			}else
		//}
		//if (j == school.size())
		{
			flag[student[i].school] = true;
			School temp;
			//for (int k = 0; k < strlen(student[i].school); k++)
			//{
			//	temp.name[k] = student[i].school[k];
			//}
			//temp.name[strlen(student[i].school)] = '\0';
			temp.name = student[i].school;
			if (student[i].num[0] == 'A')
				temp.score = student[i].score;
			else if (student[i].num[0] == 'T')
				temp.score = student[i].score * 1.5;
			else
				temp.score = student[i].score / 1.5;
			temp.stuNum = 1;
			school.push_back(temp);
		}
	}

	sort(school.begin(),school.end(),cmp);
	//printf("%d\n",school.size());
	cout << school.size() << '\n';
	for (int i = 0; i < school.size(); i++)
	{
		if (i == 0 || school[i].score != school[i-1].score)
		{
			//printf("%d %s %d %d\n",i + 1, school[i].name, school[i].score, school[i].stuNum);
			cout << i + 1 << ' ' << school[i].name << ' ' << school[i].score << ' ' << school[i].stuNum <<endl;
		}else
		{
			//printf("%d %s %d %d\n",i, school[i].name, school[i].score, school[i].stuNum);
			cout << i << ' ' << school[i].name << ' ' << school[i].score << ' ' << school[i].stuNum <<endl;
		}
	}

	return 0;
}