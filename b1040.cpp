#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int tempA = -1;
	int numberP = 0;
	int numberT = 0;
	long long sum = 0;
	cin >> s;

	for (int i = 0, a = 0; i < s.size(); i++)
	{
		if (!a && s[i] == 'A')
		{
			a = 1;
			tempA = i;
		}
		if (!a && s[i] == 'P')
			++numberP;

		else if (a && s[i] == 'T')
			++numberT;
	}

	sum += numberP * numberT;
	for (int i = tempA + 1; i < s.size(); i++)
	{
		if (s[i] == 'P')
			++numberP;
		else if (s[i] == 'T')
			--numberT;
		else
		{
			sum += (long long)numberP * (long long)numberT;
		}
	}
	cout << sum % 1000000007;


}