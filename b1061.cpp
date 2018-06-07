#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int temp;
	scanf("%d%d", &n, &m);
	int* score = new int[m];
	int* ans = new int[m];
	int* student = new int[n];

	for (int i = 0; i < m; i++)
		scanf("%d", score + i);

	for (int i = 0; i < m; i++)
		scanf("%d", ans + i);

	for (int i = 0; i < n; i++)
		student[i] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &temp);
			if (temp == ans[j])
				student[i] += score[j];
		}
		printf("%d\n", student[i]);
	}
}