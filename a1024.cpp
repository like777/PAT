#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isPalindromic(vector<int> vec)
{
	for (int i = 0; i < vec.size() / 2; i++)
	{
		if (vec[i] != vec[vec.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int c = 0;
vector<int> sum(vector<int> vec)
{
	vector<int> res;
	c = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] + c + vec[vec.size() - 1 - i] > 9)
		{
			res.push_back(vec[i] + c + vec[vec.size() - 1 - i] - 10);
			c = 1;
		}else
		{
			res.push_back(vec[i] + c + vec[vec.size() - 1 - i]);
			c = 0;
		}
	}
	if (c > 0)
	{
		res.push_back(1);
	}
	return res;
}

void print(vector<int> vec)
{
	for (int i = vec.size() - 1; i > -1; i--)
	{
		printf("%d", vec[i]);
	}
	printf("\n");
}

int main()
{
	string str;
	int k;
	cin >> str >> k;

	vector<int> n;

	for (int i = 0; i < str.size(); i++)
	{
		n.push_back(str[str.size() - 1 - i] - '0');
	}

	for (int i = 0; i <= k; i++)
	{		
		if (isPalindromic(n) || i == k)
		{
			print(n);
			printf("%d", i);
			return 0;
		}
		n = sum(n);
	}
}