#include <cstdio>
#include <map>

using namespace std;

void weekTrans(char c) {
	switch (c)
	{
	case 'A':printf("MON ");break;
	case 'B':printf("TUE ");break;
	case 'C':printf("WED ");break;
	case 'D':printf("THU ");break;
	case 'E':printf("FRI ");break;
	case 'F':printf("SAT ");break;
	case 'G':printf("SUN ");break;
	}
}

int hourTrans(char c) {
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'N')
	{
		return c - 'A' + 10;
	}
}

int main()
{
	char s1[61], s2[61], s3[61], s4[61];

	char week, hour;
	int pos;

	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	scanf("%s",s4);


	for (int i = 0, flag = 0; s1[i] != '\0' && s2[i] !='\0'; i++)
	{
		if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G' && flag == 0)
		{
			week = s1[i];
			flag ++;
		}
		else if(s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0' && s1[i] <= '9'))&& flag == 1)
		{
			hour = s1[i];
			break;
		}
	}

	for (int i = 0; s3[i] != '\0' && s4[i] !='\0'; i++)
	{
		if (s3[i] == s4[i] && ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')))
		{
			pos = i;
		}
	}
	weekTrans(week);
	printf("%02d:%02d",hourTrans(hour),pos);
	return 0;
}