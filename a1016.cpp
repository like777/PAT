#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

double price[24];

struct Time
{
	int month, day, hour, minute;
	bool type;
};

int minusTime(Time time1, Time time2)
{
	return time2.day * 60* 24 + time2.hour * 60 + time2.minute - time1.day * 60 * 24 - time1.hour * 60 - time1.minute;
}

double calculate(Time time1, Time time2)
{
	double money = 0;
	double day_money = 0;
	for (int i = 0; i < 24; i++)
		day_money += 60 * price[i];
	if (time1.hour == time2.hour && time2.minute >= time1.minute)
	{
		money = money + day_money * (time2.day - time1.day) + (time2.minute - time1.minute) * price[time1.hour + 1];
		return money;
	}
	money = money + (60 - time1.minute) * price[time1.hour % 24] + time2.minute * price[time2.hour % 24];
	if (time2.hour > time1.hour)
	{
		money += day_money * (time2.day - time1.day);
		int tmp = time1.hour + 1;
		while (tmp != time2.hour)
		{
			money += price[tmp] * 60;
			tmp = ++tmp % 24;
		}
	}else
	{
		money += day_money * (time2.day - time1.day - 1);
		int tmp = time2.hour;
		while (tmp != time1.hour + 1)
		{
			money += price[tmp] * 60;
			tmp = ++tmp % 24;
		}
	}
	return money;
}

bool cmp(Time time1, Time time2)
{
	if (time1.month == time2.month)
	{
		if (time1.day == time2.day)
		{
			if (time1.hour == time2.hour)
				return time1.minute < time2.minute;
			return time1.hour < time2.hour;
		}
		return time1.day < time2.day;
	}
	return time1.month < time2.month;
}

int main()
{
	for (int i = 0; i < 24; i++)
	{
		scanf("%lf", &price[i]);
		price[i] = price[i] / 100;
	}

	int n;
	scanf("%d", &n);
	vector<vector<Time>> data(1);
	map<string, int> people;

	string name;
	//name.resize(21);
	Time time;
	for (int i = 0, c = 0; i < n; i++)
	{
		vector<Time> tmp;
		Time time;
		cin >> name;
		//scanf("%s", &name[0]);
		if (people[name] == 0)
		{
			people[name] = ++c;
			data.push_back(tmp);
		}
		char type[9];
		scanf("%d:%d:%d:%d %s", &time.month, &time.day, &time.hour, &time.minute, type);
		if (strcmp(type, "on-line") == 0)
			time.type = true;
		else
			time.type = false;
		data[people[name]].push_back(time);
	}

	for (int i = 1; i < data.size(); i++)
	{
		sort(data[i].begin(), data[i].end(), cmp);
		for (int j = 0, flag = 0; j < data[i].size(); j++)
		{
			if (flag == 0 && !data[i][j].type)
			{
				data[i].erase(data[i].begin() + j);
				--j;
			}
			else if (flag == 1 && data[i][j].type)
			{
				data[i].erase(data[i].begin() + j - 1);
				--j;
			}
			else if (data[i][j].type)
				flag = 1;
			else 
				flag = 0;
		}
		if (data[i].size() % 2 == 1)
			data[i].erase(data[i].end() - 1);
	}

	for (map<string, int>::iterator it = people.begin(); it != people.end(); ++it)
	{
		//cout << it->first;
		//int k = 0;
		fputs(&(it->first[0]),stdout);
		//while (it -> first[k] != '\0')
			//putchar(it->first[k++]);
		printf(" %02d\n", data[it -> second][0].month);
		double total = 0;
		for (int i = 0; i < data[it -> second].size() / 2; i++)
		{
			double tmp = calculate(data[it->second][2 * i], data[it->second][2 * i + 1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", data[it->second][2 * i].day, data[it->second][2 * i].hour, data[it->second][2 * i].minute, data[it->second][2 * i + 1].day, data[it->second][2 * i + 1].hour, data[it->second][2 * i + 1].minute, minusTime(data[it->second][2 * i], data[it->second][2 * i + 1]), tmp);
			total += tmp;
		}
		printf("Total amount: $%.2f\n", total);
	}


}
