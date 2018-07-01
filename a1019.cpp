#include<cstdio>
#include<vector>

using namespace std;

bool isPalindromic(vector<int> numbers)
{
	for (int i = 0; i < numbers.size() / 2; i++)
	{
		if (numbers[i] != numbers[numbers.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int number, radix;
	scanf("%d%d", &number, &radix);

	vector<int> numbers;
	while (number > 0)
	{
		numbers.push_back(number % radix);
		number /= radix;
	}
	if (isPalindromic(numbers))
	{
		printf("Yes\n");
	}else
	{
		printf("No\n");
	}

	if (numbers.size() == 0)
	{
		printf("0");
		return 0;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", numbers[numbers.size() - 1 - i]);
	}
}