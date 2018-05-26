#include <stdio.h>

int main() {
	int n,m = 0;
	scanf("%d",&n);
	for (int i = 0;n != 1;i++) {
			if (n % 2 == 0)
				n = n/2;
			else
				n = (3*n + 1)/2;
			m ++;
	}
	printf("%d",m);
	return 0;
}
