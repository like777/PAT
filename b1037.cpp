#include <cstdio>

struct Money
{
	int galleon;
	int sickle;
	int knut;
};


int main()
{
	Money p, a, ans;
	int c = 0;
	bool n = true;
	scanf("%d.%d.%d %d.%d.%d", &p.galleon, &p.sickle, &p.knut, &a.galleon, &a.sickle, &a.knut);

	if (p.galleon * 17 * 29 + p.sickle * 29  + p.knut > a.galleon * 17 * 29 + a.sickle * 29  + a.knut)
	{
		n = false;
		ans = p;
		p = a;
		a = ans;
	}

	if (a.knut < p.knut)
	{
		ans.knut = a.knut + 29 - p.knut;
		c = 1;
	}else
	{
		ans.knut = a.knut - p.knut;
	}

	if (a.sickle - c < p.sickle)
	{
		ans.sickle = a.sickle - c + 17 - p.sickle;
		c = 1;
	}else
	{
		ans.sickle = a.sickle - c - p.sickle;
		c = 0;
	}

	ans.galleon = a.galleon - c - p.galleon;

	if (!n)
	{
		printf("-");
	}
	printf("%d.%d.%d", ans.galleon, ans.sickle, ans.knut);
}