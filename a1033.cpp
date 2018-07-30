#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Station
{
	double price;
	double distance;
	bool fill;
};

bool cmp(Station a, Station b)
{
	return a.distance < b.distance;
}

int main()
{
	double tank, distance, davg;
	int n;
	scanf("%lf%lf%lf%d", &tank, &distance, &davg, &n);

	vector<Station> stations(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &stations[i].price, &stations[i].distance);
		stations[i].fill = true;
	}

	sort(stations.begin(), stations.end(), cmp);

	if (stations[0].distance != 0)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}

	int k = 0;
	double current_tank = 0, current_price = 0;
	while (k < stations.size() && stations[k].distance < distance)
	{
		if (k != 0)
		{
			current_tank -= (stations[k].distance - stations[k - 1].distance) / davg;
		}

		if (!stations[k].fill)
		{
			++k;
			continue;
		}

		bool flag = false;
		for (int i = k + 1;i < stations.size() && stations[i].distance < distance && stations[i].distance - stations[k].distance <= tank * davg; i++)
		{
			if (stations[i].price < stations[k].price)
			{
				if (stations[i].distance - stations[k].distance > current_tank * davg)
				{
					current_price += (stations[i].distance - stations[k].distance - current_tank * davg) / davg * stations[k].price;
					current_tank += (stations[i].distance - stations[k].distance - current_tank * davg) / davg;
				}
				for (int j = k + 1; j < i; j++)
				{
					stations[j].fill = false;
				}
				flag = true;
				break;
			}
		}
		if (!flag && stations[k].distance + tank * davg <= distance)
		{
			current_price += (tank - current_tank) * stations[k].price;
			current_tank = tank;
		}
		++k;
	}

	if (stations[k - 1].distance + tank * davg >= distance)
	{
		current_price += (distance - stations[k - 1].distance - current_tank * davg) / davg * stations[k - 1].price;
		printf("%.2f", current_price);
	}else
	{
		printf("The maximum travel distance = %.2f", stations[k - 1].distance + tank * davg);
	}
}