#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	for (int i = 0; i < n; i++)
	{

		getline(cin, str);
		if (str.size() < 6)
		{
			printf("Your password is tai duan le.\n");
			continue;
		}
		int flag = 0;
		int flag2 = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (!(str[i] == '.' || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
			{
				flag = 1;
				printf("Your password is tai luan le.\n");
				break;
			}
			if (str[i] >= '0' && str[i] <= '9')
			{
				flag = 2;
			}
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			{
				flag2 = 2;
			}
		}
		if (flag == 1)
		{
			continue;
		}
		if (flag == 0)
		{
			printf("Your password needs shu zi.\n");
			continue;
		}
		if (flag2 == 0)
		{
			printf("Your password needs zi mu.\n");
			continue;
		}
		printf("Your password is wan mei.\n");
	}


}