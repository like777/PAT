#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int teams[1010] = {0};
	int teamNumber;
	int score;
	string s;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cin >> score;
		teamNumber = 0;
		int j = 0;
		for (; s[j] != '-'; j++)
		{
			teamNumber = teamNumber * 10 + s[j] - '0';
		}
		teams[teamNumber] += score;
	}
	teamNumber = 0;
	for (int i = 0; i < 1010; i++)
	{
		if (teams[teamNumber] < teams[i])
		{
			teamNumber = i;
		}
	}
	cout << teamNumber << " " << teams[teamNumber];
}