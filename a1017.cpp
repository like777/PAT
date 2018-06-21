//find_earliest函数 最小值初始值应设为数组第一个值，设为24小时会报错
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Time
{
	int hh, mm, ss;
};

int to_seconds(Time time)
{
	return time.ss + time.mm * 60 + time.hh * 3600;
}

struct Customer
{
	int arrive_time;
	int process_time;
};

bool cmp(Customer customer1, Customer customer2)
{
	return customer1.arrive_time < customer2.arrive_time;
}

int find_earliest(vector<int> counters)
{
	int time = counters[0];
	int ret = 0;
	for (int i = 1; i < counters.size(); i++)
	{
		if (counters[i] < time)
		{
			time = counters[i];
			ret = i;
		}
	}
	return ret;
}

int main()
{
	int n, k;
	double ans = 0;
	scanf("%d%d", &n, &k);

	vector<Customer> customers;
	vector<int> counters(k, 8 * 3600);

	for (int i = 0; i < n; i++)
	{
		Time time;
		int tmp = 0;
		scanf("%d:%d:%d %d", &time.hh, &time.mm, &time.ss, &tmp);
		if (tmp > 60)
			tmp = 60;
		if (to_seconds(time) <= 17 * 3600)
		{
			Customer cus;
			cus.arrive_time = to_seconds(time);
			cus.process_time = tmp;
			customers.push_back(cus);
		}
	}

	if (customers.size() == 0)
	{
		printf("0.0");
		return 0;
	}

	sort(customers.begin(), customers.end(), cmp);

	for (int i = 0; i < customers.size(); i++)
	{
		int ear = find_earliest(counters);
		
		if (counters[ear] <= customers[i].arrive_time)
		{
			counters[ear] = customers[i].arrive_time + customers[i].process_time * 60;
		}else
		{
			ans += (counters[ear] - customers[i].arrive_time);
			counters[ear] = counters[ear] + customers[i].process_time * 60;
		}
	}
	printf("%.1f", ans / 60.0 / customers.size());
}