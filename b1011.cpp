#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);
	double a, b, c;
	bool ans[10];

	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);

		if (a + b > c)
		{
			ans[i] = true;
		}else
		{
			ans[i] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (ans[i] == true)
		{
			printf("Case #%d: true\n",i + 1);
		}else
		{
			printf("Case #%d: false\n",i + 1);
		}
		
	}
	
	return 0;
}