#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int d, n;
	scanf("%d%d", &d, &n);

	vector<int> bef;
	vector<int> aft;

	bef.push_back(d);
	for (int i = 1; i < n; i++)
	{
		int flag = 10;
		int sum= 0;
		for (int j = 0; j < bef.size(); j++)
		{
			if (bef[j] != flag)
			{
				if (sum != 0)
				{
					aft.push_back(sum);
					sum = 0;
				}
				aft.push_back(bef[j]);
				flag = bef[j];
			}
			++ sum;
			if (j == bef.size() - 1)
			{
				aft.push_back(sum);
				sum = 0;
			}
		}
		bef = aft;
		aft.clear();
	}
	for (int i = 0; i < bef.size(); i++)
	{
		printf("%d", bef[i]);
	}


}