#include <string>
#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int one= 0, zero = 0;
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			sum += s[i] - 'a' + 1;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			sum += s[i] - 'A' + 1;
		}
	}

	while (sum != 0)
	{
		if (sum % 2 == 0)
		{
			++ zero;
		}else
		{
			++ one;
		}
		sum = sum / 2;
	}
	cout << zero << " " << one;
}