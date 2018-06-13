//当全为负数时要输出0，和数据开头和结尾
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int number;
	vector<int> numbers;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		numbers.push_back(number);
	}

	int max = numbers[0], prev = 0, aft = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j + i < n; j++)
		{
			sum += numbers[i + j];
			if (sum > max)
			{
				max = sum;
				prev = i;
				aft = i + j;
			}
		}
	}

	if (max < 0)
	{
		printf("0 %d %d", numbers[0], numbers[n - 1]);
	}else
		printf("%d %d %d", max, numbers[prev], numbers[aft]); 


}