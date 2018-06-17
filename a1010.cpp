//首先使用二分法
//其次在判断n2时一旦超出n1或溢出立刻跳出循环
//注意点当进制为n时最大数为n-1而非n
#include<cstdio>
#include<cstring>
#include <algorithm>

using namespace std;

int map[256];
long long n1, n2;
void createMap()
{
	for (int i = '0'; i <= '9'; i++)
		map[i] = i - '0';
	for (int i = 'a'; i <= 'z'; i++)
		map[i] = i - 'a' + 10;
}

long long calculate(char* str, int radix)
{
	n2 = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		n2 = radix * n2 + map[str[i]];
		if (n2 < 0 || n2 > n1)
			return -1;
	}
	return n2;
}

int findMax(char* str)
{
	int max = -1;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] > max)
			max = str[i];
	return map[max];
}

int main()
{
	char str1[11], str2[11];
	int tag;
	long long radix1;
	scanf("%s %s %d %lld", str1, str2, &tag, &radix1);

	if (tag == 2)
	{
		char strTmp[11];
		strcpy(strTmp, str1);
		strcpy(str1, str2);
		strcpy(str2, strTmp);
	}
	createMap();
	for (int i = 0; i < strlen(str1); i++)
		n1 = radix1 * n1 + map[str1[i]];

	long long min, max, mid;
	min = findMax(str2) + 1;
	max = n1 + 1;
	mid = (min + max) / 2;

	while(max >= min)
	{
		n2 = calculate(str2, mid);
		if (n2 == n1)
		{
			printf("%lld", mid);
			return 0;
		}
		else if (n2 < 0 || n2 > n1)
			max = mid - 1;
		else
			min = mid + 1;
		mid = (min + max) / 2;
	}
	printf("Impossible");
}