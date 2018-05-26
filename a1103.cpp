#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, p, k;
int maxsum = -1;
vector<int> temp, ans, power;


void DFS(int base, int sum, int ksum, int bsum) {
	if (sum == n && ksum == k)
	{
		if (bsum > maxsum)
		{
			ans = temp;
			maxsum = bsum;
		}
		return;
	}

	if (ksum > k || sum > n)
	{
		return;
	}

	if (sum < n && ksum < k)
	{
		if (base > 0)
		{
			temp.push_back(base);
			DFS(base, sum + power[base], ksum + 1, bsum + base);
			temp.pop_back();
			DFS(base - 1, sum, ksum, bsum);
		}
	}

}

int main() {
	scanf("%d%d%d", &n, &k, &p);

	for (int i = 0; i <= sqrt(n); i++)
	{
		power.push_back(pow(i,p));
	}

	DFS(sqrt(n), 0, 0, 0);

	if (maxsum == -1)
	{
		printf("Impossible");
	}else
	{
		
		printf("%d = %d^%d",n,ans[0], p);
		for (int j = 1; j < k; j++)
		{
			printf(" + %d^%d", ans[j], p);
		}
	}

}