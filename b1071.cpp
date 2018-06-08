#include <cstdio>

int main()
{
	int money, times;
	scanf("%d%d", &money, &times);

	int n1, n2, b, m;
	for (int i = 0; i < times; i++)
	{
		scanf("%d%d%d%d", &n1, &b, &m, &n2);
		if (m > money)
		{
			printf("Not enough tokens.  Total = %d.\n", money);
		}
		else if (n1 > n2 && b == 0 || n1 < n2 && b ==1)
		{
			money = money + m;
			printf("Win %d!  Total = %d.\n", m, money);
		}
		else
		{
			money = money - m;
			printf("Lose %d.  Total = %d.\n", m, money);
			if (money == 0)
			{
				printf("Game Over.\n");
				break;
			}
		}
	}


}