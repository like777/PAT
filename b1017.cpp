#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s1, s2;
	int b, r;
	int c = 0;
	vector<int> a;
	vector<int> q;

	cin >> s1 >> b;

	for (int i = 0; i < s1.size(); i++)
	{
		a.push_back(s1[i] - '0');
	}

	for (int i = 0; i < a.size(); i++)
	{
		q.push_back((c * 10 + a [i]) / b);
		c = (c * 10 + a[i]) % b;
	}
	if (q[0])
	{
		cout << q[0];
	}
	else if (q.size() == 1)
	{
		cout << "0";
	}
	for (int i = 1, flag = 0; i < q.size(); i++)
	{
		cout << q[i];
	}
	cout << " " << c;

	system("pause");
	return 0;
}