#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

struct StudentAnswer
{
	int number;
	string ans;
};

struct StandardAnswer
{
	int score;
	int total;
	int number;
	string ans;
	int wrong;
};

int main()
{
	int n, m;
	int max = 0;
	char c;
	string sline;
	string s;
	scanf("%d%d", &n, &m);
	StandardAnswer standardAnswer;
	StudentAnswer studentAnswer;
	vector<StandardAnswer> standardAnswers;
	vector<StudentAnswer> studentAnswers;
	vector<int> studentscore(n, 0);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &standardAnswer.score, &standardAnswer.total, &standardAnswer.number);
		for (int j = 0; j < standardAnswer.number; j++)
		{
			scanf(" %c", &c);
			s.push_back(c);
		}
		standardAnswer.ans = s;
		standardAnswer.wrong = 0;
		standardAnswers.push_back(standardAnswer);
		s.clear();
	}
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		s.clear();
		getline(cin, sline);
		for (int j = 0; j < sline.size(); j++)
		{
			if (sline[j] == '(')
			{
				studentAnswer.number = sline[++j] - '0';
				while (sline[++j] != ')')
				{
					if (sline[j] != ' ')
						s.push_back(sline[j]);
				}
				studentAnswer.ans = s;
				studentAnswers.push_back(studentAnswer);
			}
			s.clear();
		}
		for (int j = 0; j < m; j++)
		{
			if (studentAnswers[j].number != standardAnswers[j].number)
			{
				++standardAnswers[j].wrong;
			}else
			{
				if (studentAnswers[j].ans != standardAnswers[j].ans)
				{
					++standardAnswers[j].wrong;
				}else
				{
					studentscore[i] += standardAnswers[j].score;
				}
			}
		}
		cout << studentscore[i] << endl;
		studentAnswers.clear();
	}

	for (int i = 0; i < m; i++)
	{
		if (standardAnswers[i].wrong > max)
		{
			max = standardAnswers[i].wrong;
		}
	}
	if (max == 0)
	{
		cout << "Too simple" << endl;
		return 0;
	}
	cout << max;
	for (int i = 0; i < m; i++)
	{
		if (standardAnswers[i].wrong == max)
		{
			cout << " " << i + 1;
		}
	}
}