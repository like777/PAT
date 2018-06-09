#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Answer
{
	double score;
	int number;
	int total;
	vector<char> ans;
};

int main()
{
	int n, m;
	cin >> n >> m;

	Answer answer;
	vector<map<char, bool>> check(m);
	vector<map<char, bool>> check2(m);
	vector<Answer> standardAnswers;
	vector<vector<Answer>> studentsAnswers(n);
	vector<map<char, int>> count(m);

	for (int i = 0; i < m; i++)
	{
		cin >> answer.score >> answer.total >> answer.number;
		char c;
		for (int j = 0; j < answer.number; j++)
		{
			cin >> c;
			answer.ans.push_back(c);
			check[i][c] = true;
		}
		standardAnswers.push_back(answer);
		answer.ans.clear();
	}

	string str;
	getline(cin, str);
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		studentsAnswers[i].resize(m);
		for (int j = 0, flag = 0, f = 0; j < str.size(); j++)
		{
			f = 0;
			if (str[j] == '(')
			{
				studentsAnswers[i][flag].number = str[++j] - '0';
				int k = 0;
				while (str[j + k] != ')')
				{
					if (str[j + k] >= 'a' && str[j + k] <= 'e')
						studentsAnswers[i][flag].ans.push_back(str[j + k]);
					++k;
				}
				for (int l = 0; l < studentsAnswers[i][flag].ans.size(); l++)
				{
					if (check[flag][studentsAnswers[i][flag].ans[l]] == false)
					{
						++count[flag][studentsAnswers[i][flag].ans[l]];
						f = 1;
					}
					check2[flag][studentsAnswers[i][flag].ans[l]] = true;
				}
				if (f == 0)
				{
					if (studentsAnswers[i][flag].ans.size() == standardAnswers[flag].ans.size())
					{
						studentsAnswers[i][flag].score = standardAnswers[flag].score;
					}else
						studentsAnswers[i][flag].score = standardAnswers[flag].score / 2;
				}else	
					studentsAnswers[i][flag].score = 0;
				for (map<char, bool>::iterator it = check[flag].begin(); it != check[flag].end(); it ++)
				{
					if ((*it).second == true && check2[flag][(*it).first] == false)
					{
						++count[flag][(*it).first];
					}
				}
				check2.clear();
				check2.resize(m);
				++ flag;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += studentsAnswers[i][j].score;
		}
		printf("%.1f\n", sum);
	}

	int max = 0;
	for (int i = 0; i < m; i++)
	{
		for (map<char, int>::iterator it = count[i].begin(); it != count[i].end(); it++)
		{
			if ((*it).second > max)
				max = (*it).second;
		}
	}
	if (max == 0)
	{
		cout << "Too simple" <<endl;
	}else
	{
		for (int i = 0; i < m; i++)
		{
			for (map<char, int>::iterator it = count[i].begin(); it != count[i].end(); it++)
			{
				if ((*it).second == max)
					cout << max << " " << i + 1 << "-" << (*it).first << endl;
			}
		}
	}
}