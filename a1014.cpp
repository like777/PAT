#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Time
{
	int hour;
	int minute;
};

struct People
{
	Time served_time;
	int proceeding_time;
	Time leave_time;
};

Time addTime (Time time, int minutes)
{
	int min, hour;
	min = minutes % 60;
	hour = minutes / 60;
	if (min + time.minute >= 60)
	{
		time.minute = min + time.minute - 60;
		time.hour += hour + 1;
	}else
	{
		time.minute += min;
		time.hour += hour;
	}
	return time;
}

int cmpTime (Time time1, Time time2)
{
	if (time1.hour > time2.hour)
		return -1;
	else if (time1.hour < time2.hour)
		return 1;
	else if (time1.minute > time2.minute)
		return -1;
	else if (time1.minute < time2.minute)
		return 1;
	else
		return 0;
}

int findEarliest (vector<queue<People>> que)
{
	int ans;
	Time min;
	min.hour = 24;
	min.minute = 60;
	for (int i = 0; i < que.size(); i++)
		if (cmpTime (que[i].front().leave_time, min) > 0)
		{
			min = que[i].front().leave_time;
			ans = i;
		}
	return ans;
}

int main()
{
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);

	vector<queue<People>> que(n);
	vector<People> peoples;
	Time tmp = {8, 0};
	vector<Time> line_times(n, tmp);

	for (int i = 0, tmp = 0; i < k; i++)
	{
		People people;
		scanf("%d", &people.proceeding_time);
		if (i < n * m)
		{
			people.served_time = line_times[i % n];
			people.leave_time = addTime(line_times[i % n], people.proceeding_time);
			line_times[i % n] = people.leave_time;
			que[i % n].push(people);
		}
		else
		{
			int ear = findEarliest(que);
			people.served_time = line_times[ear];
			people.leave_time = addTime(line_times[ear], people.proceeding_time);
			line_times[ear] = people.leave_time;
			que[ear].pop();
			que[ear].push(people);
		}
		peoples.push_back(people);
	}

	Time closeTime = {17, 0};
	for (int i = 0, number; i < q; i++)
	{
		scanf("%d", &number);
		if (cmpTime(closeTime, peoples[number - 1].served_time) > 0)
		{
			printf("Sorry\n");
		}else
			printf("%02d:%02d\n", peoples[number - 1].leave_time.hour, peoples[number - 1].leave_time.minute);
	}
}