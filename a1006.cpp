#include <iostream>
#include <string>

using namespace std;

int main()
{
	int m;
	scanf("%d", &m);

	string id_number, sign_in_time, sign_out_time;

	string min = "23:59:59";
	string max = "00:00:00";
	string minPeople;
	string maxPeople;
	for (int i = 0; i < m; i++)
	{
		cin >> id_number >> sign_in_time >> sign_out_time;
		if (sign_in_time <= min)
		{
			min = sign_in_time;
			minPeople = id_number;
		}
		if (sign_out_time >= max)
		{
			max = sign_out_time;
			maxPeople = id_number;
		}
	}

	cout << minPeople << " " << maxPeople;

}