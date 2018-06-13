#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct Number
{
	int e;
	double a;
};

int main()
{
	int k1, k2;
	Number number;
	vector<Number> numbers1;
	vector<Number> numbers2;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++)
	{
		scanf("%d%lf", &number.e, &number.a);
		numbers1.push_back(number);
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++)
	{
		scanf("%d%lf", &number.e, &number.a);
		numbers2.push_back(number);
	}

	map<int, double> sum;
	for (int i = 0; i < numbers1.size(); i++)
	{
		for (int j = 0; j < numbers2.size(); j++)
		{
			sum[numbers1[i].e + numbers2[j].e] += numbers1[i].a * numbers2[j].a;
		}
	}

	int count = 0;
	for (map<int, double>::reverse_iterator it = sum.rbegin(); it != sum.rend(); ++it)
	{
		if (it->second != 0.0 && it->second != -0.0)
		{
			count++;
		}
	}
	printf("%d", count);

	for (map<int, double>::reverse_iterator it = sum.rbegin(); it != sum.rend(); ++it)
	{
		if (it->second != 0.0 && it->second != -0.0)
		{
			printf(" %d %.1f", it -> first, it -> second);
		}
	}


}