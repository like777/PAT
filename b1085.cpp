#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

void change(char str[7])
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

struct School
{
	char schoolName[7];
	int aScore, tScore, bScore, totalScore;
	int studentsNum;
}schools[100010];

bool cmp(School school1, School school2)
{
	if (school1.totalScore == school2.totalScore)
	{
		if (school1.studentsNum == school2.studentsNum)
		{
			return strcmp(school1.schoolName, school2.schoolName) < 0;
		}
		return school1.studentsNum < school2.studentsNum;
	}
	return school1.totalScore > school2.totalScore;
}

int main()
{
	int n;
	scanf("%d", &n);

	map<string, int> schoolNumbers;

	int c = 0;
	for (int i = 0; i < n; i++)
	{
		char str1[7], str2[7];
		//string str;
		int grade;
		scanf("%s %d %s", str1, &grade, str2);
		change(str2);
		//str = str2;
		if (schoolNumbers[str2] == 0)
		{
			schoolNumbers[str2] = ++c;
		}
		strcpy(schools[schoolNumbers[str2]].schoolName , str2);
		if (str1[0] == 'A')
			schools[schoolNumbers[str2]].aScore += grade;
		else if (str1[0] == 'T')
			schools[schoolNumbers[str2]].tScore += grade;
		else
			schools[schoolNumbers[str2]].bScore += grade;
		++schools[schoolNumbers[str2]].studentsNum;
	}
	for (int i = 1; i <= c; i++)
	{
		schools[i].totalScore = schools[i].aScore + schools[i].tScore * 1.5 + schools[i].bScore / 1.5;
	}

	sort(schools + 1, schools + c + 1, cmp);

	int score = 0;
	int rank = 1;
	printf("%d\n", c);
	for (int i = 1; i <= c; i++)
	{
		if (schools[i].totalScore != score)
		{
			printf("%d", i);
			score = schools[i].totalScore;
			rank = i;
		}else
		{
			printf("%d", rank);
		}
		printf(" %s %d %d\n", schools[i].schoolName, schools[i].totalScore, schools[i].studentsNum);
	}
}