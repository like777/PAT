#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	double temp;
	vector<double> numbers;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &temp);
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());
	temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			temp += numbers[i] / pow(2, n - i - 1);
		else
			temp += numbers[i] / pow(2, n - i);
	}
	printf("%d", (int)temp);
}