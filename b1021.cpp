#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	string s;
	vector <int> numbers;

	for (int i = 0; i < 10; i++)
	{
		numbers.push_back(0);
	}

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		++ numbers[s[i] - '0'];
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i])
		{
			cout << i << ":" << numbers[i] << endl;
		}
	}
	system("pause");
	return 0;
}