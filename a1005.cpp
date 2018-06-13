#include <iostream>
#include <string>
#include <vector>

using namespace std;

string trans[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
	string str;
	getline(cin, str);

	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		ans += str[i] - '0';
	}

	if (ans == 0)
	{
		cout << "zero";
		return 0;
	}
	vector<int> number;
	while (ans > 0)
	{
		number.push_back(ans % 10);
		ans /= 10;
	}
	for (int i = 0; i < number.size(); i++)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << trans[number[number.size() - i - 1]];
	}
}