#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	scanf("%d%d",&N,&M);

	int* A;
	A = (int*)malloc(N*sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&A[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (i < N - 1)
		{
			printf("%d ",A[(N-M%N+i)%N]);
		}else
		{
			printf("%d",A[(N-M%N+i)%N]);
		}
	}
}