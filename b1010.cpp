#include <iostream>
#include <vector>
using namespace std;

struct Number
{
	int a;
	int n;
};

int main() 
{
	vector<Number> preNumbers;
	preNumbers.end();
	vector<Number> alterNumbers;

	Number temp;

	while (cin >> temp.a >> temp.n)
	{
		preNumbers.push_back(temp);
	}

	for (int i = 0; i < preNumbers.size(); i++)
	{
		temp.a = preNumbers[i].a * preNumbers[i].n;
		temp.n = preNumbers[i].n - 1;
		if (temp.a != 0)
		{
			alterNumbers.push_back(temp);
		}
	}

	if (!alterNumbers.empty())
	{
		cout << "0 0";
	}
	else
	{
		cout << alterNumbers[0].a << " " << alterNumbers[0].n;
		for (int i = 1; i < alterNumbers.size(); i++)
		{
			cout << " " << alterNumbers[i].a << " " << alterNumbers[i].n;
		}
	}
	
	return 0;

}