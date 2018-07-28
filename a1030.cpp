#include<cstdio>
#include<vector>
#include<deque>
#include<map>

using namespace std;

int n, m, start, destination;
int shortest_distance, shortest_cost;
deque<int> current_q, q;
map<int, bool> mp;

struct City
{
	vector<int> nearby_cities;
	vector<int> distance;
	vector<int> cost;
}cities[510];

void DFS(int current_city, int current_distance, int current_cost)
{
	if (current_city == destination)
	{
		if (current_distance < shortest_distance)
		{
			shortest_distance = current_distance;
			shortest_cost = current_cost;
			q = current_q;
		}
		else if (current_distance == shortest_distance && current_cost < shortest_cost)
		{
			shortest_cost = current_cost;
			q = current_q;
		}
	}else
	{
		for (int i = 0; i < cities[current_city].nearby_cities.size(); i++)
		{
			if (!mp[cities[current_city].nearby_cities[i]])
			{
				mp[cities[current_city].nearby_cities[i]] = true;
				current_q.push_back(cities[current_city].nearby_cities[i]);
				DFS(cities[current_city].nearby_cities[i], current_distance + cities[current_city].distance[i], current_cost + cities[current_city].cost[i]);
				mp[cities[current_city].nearby_cities[i]] = false;
				current_q.pop_back();
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &start, &destination);

	for (int i = 0, a, b, distance, cost; i < m; i++)
	{
		scanf("%d%d%d%d", &a, &b, &distance, &cost);
		cities[a].nearby_cities.push_back(b);
		cities[a].distance.push_back(distance);
		cities[a].cost.push_back(cost);
		cities[b].nearby_cities.push_back(a);
		cities[b].distance.push_back(distance);
		cities[b].cost.push_back(cost);
		shortest_distance += distance;
		shortest_cost += cost;
	}

	mp[start] = true;
	current_q.push_back(start);
	DFS(start, 0, 0);
	printf("%d", q.front());
	q.pop_front();
	while (!q.empty())
	{
		printf(" %d", q.front());
		q.pop_front();
	}
	printf(" %d", shortest_distance);
	printf(" %d", shortest_cost);
}