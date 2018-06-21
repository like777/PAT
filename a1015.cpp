#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int number1, radix;
	while (1)
	{
		scanf("%d%d", &number1, &radix);
		if (number1 < 0)
			return 0;
		if (!isPrime(number1))
		{
			printf("No\n");
			continue;
		}
		vector<int> numbers;
		while (number1 > 0)
		{
			numbers.push_back(number1 % radix);
			number1 /= radix;
		}
		int number2 = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			number2 = number2 * radix + numbers[i];
		}
		if (isPrime(number2))
			printf("Yes\n");
		else
			printf("No\n");
	}

}