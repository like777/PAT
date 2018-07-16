#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int n[21];
	int count[10];
	memset(n, -1, 21 * sizeof(int));
	memset(count, 0, 10 * sizeof(int));

	for (int i = 0; i < str.size(); i++)
	{
		n[str.size() - 1 - i] = str[i] - '0';
		++count[str[i] - '0'];
	}

	int c = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (n[i] * 2 + c> 9)
		{
			n[i] = n[i] * 2 + c - 10;
			c = 1;
		}else
		{
			n[i] = n[i] * 2 + c;
			c = 0;
		}
	}

	if (c == 1)
	{
		n[str.size()] = 1;
	}

	for (int i = 0; i < 20; i++)
	{
		if (n[i] == -1)
		{
			break;
		}
		--count[n[i]];
	}
	
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		if (count[i] != 0)
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		printf("Yes\n");
	}else
	{
		printf("No\n");
	}

	for (int i = 20; i > -1; i--)
	{
		if (n[i] != -1)
		{
			printf("%d", n[i]);
		}
	}


}