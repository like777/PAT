/*一定要用 long long！！！
*/

#include <cstdio>
#include <math.h>

struct Number
{
	long long k;
	long long a;
	long long b;
};

long long calculateCommon(long long i1, long long i2)
{
	if (i1 == 0 || i2 == 0)
	{
		return 1;
	}
	long long i;
	i1 = abs(i1);
	i2 = abs(i2);
	if (i1 > i2)
	{
		if (i1 % i2 == 0)
		{
			return i2;
		}else
		{
			return calculateCommon(i1 % i2, i2);
		}
	}
	else
	{
		if (i2 % i1 == 0)
		{
			return i1;
		}else
		{
			return calculateCommon(i2 % i1, i1);
		}
	}
}

Number standard(Number number)
{
	long long i;
	if (double(number.k) + double(number.a) / double(number.b) >= 0)
	{
		if (number.a < 0 && number.b < 0)
		{
			number.a = -number.a;
			number.b = -number.b;
		}
		else if (number.a < 0 && number.b > 0)
		{
			number.a = number.k * number.b + number.a;
			number.k = 0;
		}
		number.k = number.k + number.a / number.b;
		i = calculateCommon(number.a, number.b);
		number.a = (number.a % number.b) / i;
		number.b = number.b / i;
	}else
	{
		if (number.a > 0 && number.b < 0)
		{
			number.a = -number.a;
			number.b = -number.b;
		}
		else if (number.a > 0 && number.b > 0)
		{
			number.a = number.k * number.b + number.a;
			number.k = 0;
		}
		number.k = number.k + number.a / number.b;
		i = calculateCommon(number.a, number.b);
		number.a = (number.a % number.b) / i;		
		number.b = number.b / i;


	}
	return number;
}

void printFunc(Number number)
{
	if ((double)number.a + (double)number.k * (double)number.b < 0)
	{
		printf("(");
	}
	if (number.k != 0)
	{
		if (number.a == 0)
		{
			printf("%lld", number.k);
		}else
		{
			printf("%lld ", number.k);
		}

	}
	else if (number.a < 0)
	{
		printf("-");
	}
	if (number.a > 0)
	{
		printf("%lld/%lld", number.a, number.b);
	}
	else if (number.a < 0)
	{
		printf("%lld/%lld", -number.a , number.b );
	}
	else if (number.k == 0)
	{
		printf("0");
	}
	if ((double)number.a + (double)number.k * (double)number.b < 0)
	{
		printf(")");
	}
}

Number add(Number number1, Number number2)
{
	Number number;
	number.k = number1.k + number2.k;
	number.a = number1.a * number2.b + number2.a * number1.b;
	number.b = number1.b * number2.b;
	number = standard(number);
	return number;
}

Number minus(Number number1, Number number2)
{
	Number number;
	number.k = number1.k - number2.k;
	number.a = number1.a * number2.b - number2.a * number1.b;
	number.b = number1.b * number2.b;
	number = standard(number);
	return number;
}

Number multiply(Number number1, Number number2)
{
	Number number;
	number.k = 0;
	number.a = (number1.a + number1.k * number1.b) * (number2.a + number2.k * number2.b);
	number.b = number1.b * number2.b;
	number = standard(number);
	return number;
}

Number eliminate(Number number1, Number number2)
{
	Number number;
	number.k = 0;
	number.a = (number1.a + number1.k * number1.b) * number2.b;
	number.b = (number2.a + number2.k * number2.b) * number1.b;
	number = standard(number);
	return number;
}

int main() 
{
	Number number1, number2;
	number1.k = number2.k = 0;
	scanf("%lld/%lld %lld/%lld", &number1.a, &number1.b, &number2.a, &number2.b);
	number1 = standard(number1);
	number2 = standard(number2);

	printFunc(number1);
	printf(" + ");
	printFunc(number2);
	printf(" = ");
	printFunc(add(number1, number2));
	printf("\n");

	printFunc(number1);
	printf(" - ");
	printFunc(number2);
	printf(" = ");
	printFunc(minus(number1, number2));
	printf("\n");

	printFunc(number1);
	printf(" * ");
	printFunc(number2);
	printf(" = ");
	printFunc(multiply(number1, number2));
	printf("\n");

	printFunc(number1);
	printf(" / ");
	printFunc(number2);
	printf(" = ");
	if (number2.a == 0 && number2.k == 0)
	{
		printf("Inf");
	}else
	{
		printFunc(eliminate(number1, number2));
	}
}