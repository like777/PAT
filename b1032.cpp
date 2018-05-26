#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

int main() {
	int N;
	int* p;
	int score;
	int max = 1;
	scanf("%d",&N);
	p = (int*)malloc((N+1)*sizeof(int));
	memset(p,0,(N+1)*sizeof(int));

	for (int j = 1, i = 0; i < N; i++)
	{
		scanf("%d%d",&j,&score);
		p[j] = p[j] + score;
	}
	for (int i = 1; i <= N; i++)
	{
		if (p[i] > p[max])
		{
			max = i;
		}
	}
	printf("%d %d",max,p[max]);
}
