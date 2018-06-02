#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	string a, b;
	int numberA, numberB;
	cin >> a >> b;
	vector<int> ans;
	
	for (int i = 0; a.size() > 0 || b.size() > 0; i++)
	{
		if (a.size())
		{
			numberA = *(a.end() - 1) - '0';
		}else
		{
			numberA = 0;
		}
		if (b.size())
		{
			numberB = *(b.end() - 1) - '0';
		}else
		{
			numberB = 0;
		}


		if (i % 2 == 0)
		{
			ans.push_back((numberA + numberB) % 13);
		}else
		{
			if (numberB - numberA >= 0)
			{
				ans.push_back(numberB - numberA);
			}else
			{
				ans.push_back(numberB + 10 - numberA);
			}
		}
		if (a.size())
		{
			a.pop_back();
		}
		if (b.size())
		{
			b.pop_back();
		}

	}
	for (int i = ans.size() - 1, flag = 0; i > -1; i--)
	{
		if (ans[i] == 10)
		{
			printf("J");
			flag = 1;
		}
		else if (ans[i] == 11)
		{
			printf("Q");
			flag = 1;
		}
		else if (ans[i] == 12)
		{
			printf("K");
			flag = 1;
		}
		else
		{
			printf("%d", ans[i]);
		}
		
		/*else if (flag != 0)
		{
			printf("%d", ans[i]);
		}else if (ans[i] != 0)
		{
			printf("%d", ans[i]);
		}*/
	}
}