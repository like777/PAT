#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

char units[100][100] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char tens[100][100] = {"0", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


void translate_to_mars(int n)
{
	int m1, m2;
	m1 = n / 13;
	m2 = n % 13;
	if (m1 == 0)
		cout << units[m2];
		//printf("%s", units[m2]);
	else if (m2 == 0)
		cout << units[m1];
		//printf("%s", tens[m1]);
	else
		cout << tens[m1] << " " << units[m2];
		//printf("%s %s", tens[m1], units[m2]);
}

int main()
{
	
	int n;
	string s;
	int tempEarth = 0;
	char tempTens[5];
	char tempUnits[5];
	int earthNumber = 0;

	cin >> n;
	getchar();
	
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		if (s[0] >= '0' && s[0] <= '9')
		{
			tempEarth = 0;
			for (int j = 0; j < s.size(); j++)
				tempEarth = tempEarth * 10 + s[j] - '0';
			translate_to_mars(tempEarth);
		}else
		{
			tempTens[0] = '\0';
			tempUnits[0] = '\0';
			if (s.size() > 4)
			{
				for (int j = 0; s[j] != ' '; j++)
					tempTens[j] = s[j];
				tempTens[3] = '\0';
				for (int j = 4; j < s.size(); j++)
					tempUnits[j - 4] = s[j];
				tempUnits[3] = '\0';
			}
			else if (s.size() == 4)
			{
				for (int j = 0; j < 4; j++)
					tempUnits[j] = s[j];
				tempUnits[4] = '\0';
			}else
			{
				for (int j = 0; j < s.size(); j++)
					tempUnits[j] = s[j];
			}
			for (int j = 0; j < 13; j++)
			{
				if (!strcmp(tempTens, tens[j]))
				{
					earthNumber += j * 13;
					break;
				}
			}
			for (int j = 0; j < 13; j++)
			{
				if (!strcmp(tempUnits, units[j]))
				{
					earthNumber += j;
					break;
				}
			}
			for (int j = 0; j < 13; j++)
			{
				if (!strcmp(tempUnits, tens[j]))
				{
					earthNumber += j * 13;
					break;
				}
			}
			cout << earthNumber;
			earthNumber = 0;
			//printf("%d", earthNumber);
		}
		cout << endl;
	}
	
	return 0;
}