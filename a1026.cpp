#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct Customer
{
	int arrive_time, start_time, play_time;
	bool vip;
};

bool cmp(Customer a, Customer b)
{
	return a.arrive_time < b.arrive_time;
}

int find_earliest(vector<int> vec)
{
	int min = vec[0];
	int ret = 0;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < min)
		{
			min = vec[i];
			ret = i;
		}
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d", &n);

	vector<Customer> customers(n);
	for (int i = 0, hh, mm, ss, tag; i < n; i++)
	{
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &customers[i].play_time, &tag);
		customers[i].play_time *= 60;
		customers[i].arrive_time = hh * 3600 + mm * 60 + ss;
		if (tag == 1)
			customers[i].vip = true;
	}

	sort(customers.begin(), customers.end(), cmp);

	int k, m, temp;
	scanf("%d%d", &k, &m);
	map<int, bool> vip_table;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		vip_table[temp - 1] = true;
	}

	vector<int> table_time(k, 8 * 3600);
	vector<int> table_number(k, 0);

	for (int i = 0; i < customers.size(); i++)
	{
		int t = find_earliest(table_time);
		if (table_time[t] >= 21 * 3600)
		{
			customers.resize(i);
			break;
		}
		bool flag = false;
		for (int j = 0; j < table_time.size(); j++)
		{
			if (table_time[j] <= customers[i].arrive_time)
			{
				customers[i].start_time = customers[i].arrive_time;
				table_time[j] = customers[i].start_time + customers[i].play_time;
				++table_number[j];
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			int flg = false;
			if (vip_table[t])
			{
				for (int j = i; j < customers.size() && customers[j].arrive_time <= table_time[t]; j++)
				{
					if (customers[j].vip)
					{
						customers[j].start_time = table_time[t];
						table_time[t] += customers[j].play_time;
						++table_number[t];
						flg = true;
						customers.insert(customers.begin() + i, customers[j]);
						customers.erase(customers.begin() + j + 1);
						break;
					}
				}
			}
			if (!vip_table[t] || !flg)
			{
				customers[i].start_time = table_time[t];
				table_time[t] += customers[i].play_time;
				++table_number[t];
			}

		}
	}
	
	for (int i = 0; i < customers.size(); i++)
	{
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", customers[i].arrive_time / 3600,
			(customers[i].arrive_time - customers[i].arrive_time / 3600 * 3600) / 60,
			customers[i].arrive_time % 60,
			customers[i].start_time / 3600,
			(customers[i].start_time % 3600 - customers[i].play_time % 60) / 60,
			customers[i].start_time % 60,
			(customers[i].start_time - customers[i].arrive_time + 30) / 60);
	}

	for (int i = 0; i < table_number.size(); i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", table_number[i]);
	}
}