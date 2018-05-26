#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() {
	int d, n;
	scanf("%d%d", &d, &n);

	//vector<vector<int>> s;
	//vector<int> t;
	//vector<int> temp(10);

	int s[40][20];
	int temp[10];

	s[0][0] = d;
	s[0][1] = -1;

	for (int i = 1; i < n; i++)
	{
		memset(&temp,0,10);
		for (int j = 0; s[i - 1][j] != -1; j++)
		{
			++ temp[s[i - 1][j]];
		}
		s[i][0] = d;
		s[i][1] = temp[s[i - 1][d]];
		int k = 2;
		for (int j = 0; j < 10; j++)
		{
			if (j == d)
			{
				continue;
			}else
			{
				s[i][k] = j;
				++k;
				s[i][k] = temp[j];
				++k;
			}
		}
		s[i][k] = -1;
	}
}