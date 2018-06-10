#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Student
{
	string num;
	double score;
};

struct School
{
	string name;
	double score;
	vector<Student> students;
};

bool cmp(School school1, School school2)
{
	if (school1.score == school2.score)
	{
		if (school1.students.size() == school2.students.size())
		{
			return school1.name < school2.name;
		}else
		{
			return school1.students.size() < school2.students.size();
		}
	}
	return school1.score > school2.score;
}

string change(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] - 'A' + 'a';
		}
	}
	return s;

}
int main() {
	int n;
	scanf("%d",&n);

	map<string,School> schools;

	for (int i = 0; i < n; i++)
	{
		Student student;
		string s;
		cin >> student.num;
		scanf("%lf", &student.score);
		cin >> s;
		s = change(s);
		schools[s].name = s;
		schools[s].score = 0;
		schools[s].students.push_back(student);
	}

	vector<School> tSchool;
	for (map<string, School>::iterator it = schools.begin(); it != schools.end(); ++it)
	{
		for (int i = 0; i < (*it).second.students.size(); i++)
		{
			if ((*it).second.students[i].num[0] == 'A')
			{
				(*it).second.score += (*it).second.students[i].score;
			}
			else if ((*it).second.students[i].num[0] == 'T')
			{
				(*it).second.score += 1.5 * (*it).second.students[i].score;
			}else
			{
				(*it).second.score += (*it).second.students[i].score / 1.5;
			}
		}
		(*it).second.score = (int)(*it).second.score;
		tSchool.push_back((*it).second);
	}
	sort(tSchool.begin(), tSchool.end(), cmp);

	//cout << tSchool.size() << endl;
	printf("%d\n", tSchool.size());
	int m = 1;
	int score = tSchool[0].score;
	for (int i = 0; i < tSchool.size(); i++)
	{
		if (tSchool[i].score == score)
		{
			printf("%d", m);;
		}else
		{
			printf("%d", i + 1);
			m = i + 1;
			score = tSchool[i].score;
		}
		//cout << " " << tSchool[i].name << " " << (int)tSchool[i].score << " " << tSchool[i].students.size() << endl;
		printf(" ");
		cout << tSchool[i].name;
		printf(" %d %d\n", (int)tSchool[i].score, tSchool[i].students.size());
	}
	return 0;
}