#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int cmax, n, need_bike, extra_bike, save_need_bike, save_extra_bike, problem_station;
vector<int> road, save_road;
vector<int> current_bike(1);
vector<vector <int>> stations(n + 1);
map<int, bool> check;
int min_length;

void DFS(int current_length, int current_station)
{
	if (current_length > min_length)
	{
		return;
	}
	if (current_station == problem_station && current_length < min_length)
	{
		min_length = current_length;
		need_bike = 0;
		extra_bike = 0;
		for (int i = 0; i < road.size(); i++)
		{
			if (current_bike[road[i]] >= cmax / 2)
			{
				extra_bike += current_bike[road[i]] - cmax / 2 - need_bike;
			}else
			{
				if (extra_bike > cmax / 2 - current_bike[road[i]])
				{
					extra_bike -= cmax / 2 - current_bike[road[i]];
				}else
				{
					need_bike += cmax / 2 - current_bike[road[i]] - extra_bike;
					extra_bike = 0;
				}
			}
		}
		save_road = road;
		save_extra_bike = extra_bike;
		save_need_bike = need_bike;
		return;
	}
	if (current_station == problem_station && current_length == min_length)
	{
		need_bike = 0;
		extra_bike = 0;
		for (int i = 0; i < road.size(); i++)
		{
			if (current_bike[road[i]] >= cmax / 2)
			{
				extra_bike += current_bike[road[i]] - cmax / 2 - need_bike;
			}else
			{
				if (extra_bike > cmax / 2 - current_bike[road[i]])
				{
					extra_bike -= cmax / 2 - current_bike[road[i]];
				}else
				{
					need_bike += cmax / 2 - current_bike[road[i]] - extra_bike;
					extra_bike = 0;
				}
			}
		}
		if (save_extra_bike > 0 && need_bike > 0 || save_need_bike * need_bike > 0 && abs(need_bike) < abs(save_need_bike) || need_bike == 0 && extra_bike == 0)
		{
			save_need_bike = need_bike;
			save_extra_bike = extra_bike;
			save_road = road;
		}
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i] && stations[current_station][i] != 0)
		{
			check[i] = true;
			road.push_back(i);
			DFS(current_length + stations[current_station][i], i);
			road.pop_back();
			check[i] = false;
		}
	}
}

int main()
{
	int m;
	scanf("%d%d%d%d", &cmax, &n, &problem_station, &m);

	for (int i = 0, tmp; i < n; i++)
	{
		scanf("%d", &tmp);
		current_bike.push_back(tmp);
	}

	stations.resize(n + 1);
	for (int i = 0; i < n + 1; i++)
		stations[i].resize(n + 1);

	for (int i = 0, tmp1, tmp2, tmp3; i < m; i++)
	{
		scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
		stations[tmp1][tmp2] = tmp3;
		stations[tmp2][tmp1] = tmp3;
		min_length += tmp3;
	}

	check[0] = true;
	DFS(0, 0);

	printf("%d 0", save_need_bike);

	for (int i = 0; i < save_road.size(); i++)
	{
		printf("->%d", save_road[i]);
	}
	printf(" %d", save_extra_bike);
}