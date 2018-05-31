/*测试点2应该是当你输入相同的已进行部分插入排序的数列，再进行下一次插入的时候，要看好已经有多少排好序了，比如输入2 3 4 1和2 3 4 1，要注意输出应该是1 2 3 4 。*/
/*mergeSort时超过size 也需要排序*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool cmp(int* numbers1, int* numbers2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (numbers1[i] != numbers2[i])
			return false;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	int* numbers;
	int* numbersTemp;
	int* numbersCmp;
	bool isInsertionSort = false;
	int size = 2;
	
	numbers = (int*)malloc(n * sizeof(int));
	numbersTemp = (int*)malloc(n * sizeof(int));
	numbersCmp = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", numbers + i);
		numbersTemp[i] = numbers[i];
	}

	for (int i = 0; i < n; i++)
		scanf("%d", numbersCmp + i);
	

	for (int i = 1, flag = 0; i <= n; i++)
	{
		if (i < n && numbersTemp[i - 1] > numbersTemp[i])
			flag = 1;
		if (flag)
		{
			sort(numbersTemp, numbersTemp + i);
			if (cmp(numbersTemp, numbersCmp, n))
			{
				isInsertionSort = true;
				if (i < n)
					sort(numbersTemp, numbersTemp + i + 1);
				printf("Insertion Sort\n");
				printf("%d", numbersTemp[0]);
				for (int i = 1; i < n; i++)
					printf(" %d", numbersTemp[i]);
				break;
			}
		}
	}
	if (!isInsertionSort)
	{
		for (int i = 0; i < n; i++)
		{
			numbersTemp[i] = numbers[i];
		}
		while (!cmp(numbersTemp, numbersCmp, n))
		{
			for (int i = 0; i < n / size; i++)
				sort(numbersTemp + size * i, numbersTemp + size * (i + 1));
			sort(numbersTemp + (n / size) * size, numbersTemp + n);
			size = size * 2;
		}
		for (int i = 0; i < n / size; i++)
		sort(numbersTemp + size * i, numbersTemp + size * (i + 1));
		sort(numbersTemp + (n / size) * size, numbersTemp + n);
		printf("Merge Sort\n");
		printf("%d", numbersTemp[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", numbersTemp[i]);
	}
}


/*
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

vector<int> insertionSort(vector<int> numbers, vector<int> cmpNumbers)
{
	int number;
	int size = numbers.size();
	int j = 1;
	while (j < size - 1 && numbers[j] > numbers[j - 1])
	{
		++ j;
	}
	for (int i = j; i < size; i++)
	{
		if (i != 0)
		{
			//for (int j = 0; j < i; j++)
			//{
			//	if (numbers[i - j] > numbers[i - j - 1])
			//	{
			//		break;
			//	}
			//	else
			//	{
			//		number = numbers[i - j];
			//		numbers[i - j] = numbers[i - j - 1];
			//		numbers[i - j - 1] = number;
			//	}
			//}
			sort(numbers.begin(), numbers.begin() + i);
		}
		if (numbers.size() > size)
		{
			return numbers;
		}
		if (cmp(numbers, cmpNumbers))
		{
			numbers.push_back(1);
		}
	}
	numbers.push_back(0);
	return numbers;
}

int i1 = 1;
vector<int> mergeSort(vector<int> numbers, vector<int> cmpNumbers)
{
	const int size = cmpNumbers.size();
	if (size == 1)
	{
		if (cmp(numbers, cmpNumbers))
		{
			numbers.push_back(1);
			return numbers;
		}else
		{
			numbers.push_back(1);
			return numbers;
		}
	}

	if (pow(2,i1) >= size)
	{
		numbers.push_back(0);
		return numbers;
	}
	else
	{
		for (int j = 0; j < size / pow(2, i1); j++)
		{
			if ((j + 1) * pow(2, i1) < size)
			{
				sort(numbers.begin() + j * pow(2, i1), numbers.begin() + (j + 1) * pow(2, i1));
			}
		}
		if (numbers.size() > size)
		{
			return numbers;
		}
		if (cmp(numbers, cmpNumbers))
		{
			numbers.push_back(1);
		}
		++ i1;
		return mergeSort(numbers,cmpNumbers);
	}
}


int main()
{
	int n;
	int number;
	vector<int> numbers;
	vector<int> temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		numbers.push_back(number);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		temp.push_back(number);
	}
	if (insertionSort(numbers, temp)[n])
	{
		printf("Insertion Sort\n");
		numbers = insertionSort(numbers, temp);

	}
	else if (mergeSort(numbers, temp)[n])
	{
		printf("Merge Sort\n");
		i1 = 1;
		numbers = mergeSort(numbers, temp);
	}
	printf("%d", numbers[0]);
	for (int i = 1; i < n; i++)
	{
		printf(" %d", numbers[i]);
	}
}
*/