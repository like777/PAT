#include <stdio.h>

int main() {
	int N;
	char C;
	scanf("%d %c",&N,&C);

	int M;
	M = (N + 1)/2;

	for (int i = 0; i < M; i++)
	{
		if (i == 0 ||i == M - 1)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%c",C);
			}
			printf("\n");
		}else
		{
			for (int j = 0; j < N; j++)
			{
				if (j == 0)
				{
					printf("%c",C);
				}
				else if (j == N - 1)
				{
					printf("%c\n",C);
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
}