#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	int n;
	int max;
	int min;
	int s[4];
	scanf("%d",&n);

	for (int i = 0;; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			s[j] = n % 10;
			n = n /10;
		}
		sort(&s[0],&s[4]);
		max = s[0] + s[1] * 10 + s[2] * 100 + s[3] * 1000;
		min = s[3] + s[2] * 10 + s[1] * 100 + s[0] * 1000;
		n = max - min;
		if (n == 0000 || n == 6174)
		{
			printf("%04d - %04d = %04d",max,min,n);
			return 0;
		}
		printf("%04d - %04d = %04d\n",max,min,n);
		
	}

}