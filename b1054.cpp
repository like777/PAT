#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int n;
	string s;
	string s1;
	double ans = 0;
	vector<string> error;
	vector<double> correct;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		bool errorFlag = false;
		bool minusFlag = false;
		int dotFlag = -1;
		double temp1 = 0;
		double temp2 = 0;
		cin >> s;
		s1 = s;
		if (s[0] == '-')
		{
			minusFlag = true;
			if (s.size() == 1)
			{
				error.push_back(s);
				break;
			}
			s1.erase(s1.begin());
		}
		for (int j = 0; j < s1.size(); j++)
		{
			if ((s1[j] > '9' || s1[j] < '0') && s1[j] != '.')
			{
				error.push_back(s);
				errorFlag = true;
				break;
			}
			if (s1[j] == '.')
			{
				if (j == 0)
				{
					error.push_back(s);
					errorFlag = true;
					break;
				}
				else if (dotFlag > -1)
				{
					error.push_back(s);
					errorFlag = true;
					break;
				}
				else if (s1[j - 1] > '9' || s1[j - 1] < '0')
				{
					error.push_back(s);
					errorFlag = true;
					break;
				}
				else
				{
					dotFlag = j;
					if (s1.size() > j + 3)
					{
						error.push_back(s);
						errorFlag = true;
						break;
					}
				}
			}

		}
		if (!errorFlag)
		{
			int k = 0;
			while (k < s1.size() && s1[k] != '.')
			{
				temp1 = temp1 * 10 + s1[k] - '0';
				++ k;
			}
			if (k != s1.size())
			{
				k = s1.size() - 1;
				while (k > -1 && s1[k] != '.')
				{
					temp2 = temp2 / 10 + (double)(s1[k] - '0') / 10;
					-- k;
				}
			}
			if (temp1 + temp2 > 1000)
			{
				error.push_back(s);
			}
			else if (minusFlag)
			{
				correct.push_back(- temp1 - temp2);
			}else
			{
				correct.push_back(temp1 + temp2);
			}
		}


	}
	for (int i = 0; i < error.size(); i++)
	{
		cout << "ERROR: " << error[i] << " is not a legal number" << endl;
	}

	if (correct.size() == 0)
	{
		cout << "The average of 0 numbers is Undefined" << endl;
	}
	else if (correct.size() == 1)
	{
		printf("The average of 1 number is %.2f\n", correct.size(), ans);
	}
	else
	{
		for (int i = 0; i < correct.size(); i++)
		{
			ans += correct[i];
		}
		printf("The average of %d numbers is %.2f\n", correct.size(), ans / (double)correct.size());
	}

}