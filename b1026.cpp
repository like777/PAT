#include <cstdio>

int main() {
	int c1, c2;
	int s, m, h;
	scanf("%d%d",&c1,&c2);

	c2 = (c2 - c1) / 10;
	if (c2 % 10 >= 5)
	{
		c2 = c2 / 10 + 1;
	}else
	{
		c2 = c2 / 10;
	}

	s = c2 % 60;
	m = ((c2 - s) / 60 ) % 60;
	h = c2 / 3600;

	printf("%02d:%02d:%02d",h,m,s);
}