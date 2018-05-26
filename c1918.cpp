#include <cstdio>
#include <string.h>

struct Node {
	double n;
	char op;
	bool flag;
};

int main() {
	char str[200];
	gets(str);
	Node node[50];
	double answer[20];
	int j = 0;
	for (int i = 0; i < strlen(str); i++)
	{ 
		static bool f = false;
		if (str[i] >= '0' && str[i] <= '9')
		{
			node[j].flag = false;
			if (f == true)
			{
				node[j - 1].n = node[j - 1].n * 10 + str[i] -'0';
			}else
			{
				node[j].n = str[i] - '0';
				++ j;
			}
			f = true;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			node[j].op = str[i];
			node[j].flag = true;
			f = false;
			++ j;
		}
	}

	double temp1 = 0, temp2;
	char temp = '+';
	for (int i = 0; i < j; i++)
	{
		if (node[i].flag == false)
		{
			temp2 = node[i].n;
		}
		
		if (node[i].flag == true)
		{
			if (node[i].op == '*')
			{
				temp2 = temp2 * node[i + 1].n;
				++ i;
			}
			else if (node[i].op == '/')
			{
				temp2 = temp2 / node[i + 1].n;
				++ i;
			}
			else if (node[i].op == '+' || node[i].op == '-')
			{
				if (temp == '+')
				{
					temp1 = temp1 + temp2;
				}else
				{
					temp1 = temp1 - temp2;
				}
				temp = node[i].op;
			}
		}
	}
	if (temp == '+')
	{
		temp1 = temp1 + temp2;
	}else
	{
		temp1 = temp1 - temp2;
	}
	printf("%.2f",temp1);
}