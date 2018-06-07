//不能等于给出的两个分数，因为要求“两个数之间的”最简分数!!!
//所以最后的循环要判断是否相等
#include <cstdio>

bool haveCommon(int n1, int n2)
{
	int temp;
	if (n1 < n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	while (n1 % n2 != 0)
	{
		temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}
	if (n2 != 1)
	{
		return true;
	}
	return false;
}

int main()
{
	int n1, n2, m1, m2;
	int temp;
	int m;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &m);

	if (n1 * m2 > n2 * m1)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
		temp = m1;
		m1 = m2;
		m2 = temp;
	}
	for (int i = n1 * m / m1 + 1, flag = 0; i < n2 * m / m2 + 1; i++)
	{
		if (i * m2 == n2 * m)
		{
			continue;
		}
		if (!haveCommon(m, i))
		{
			if (flag == 0)
			{
				printf("%d/%d", i, m);
				flag = 1;
			}else
			{
				printf(" %d/%d", i, m);
			}
		}
	}

}