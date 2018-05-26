#include <iostream>
#include <string>

using namespace std;

int getPow(string s) {
	if (s.find('.') == string::npos)
	{
		s.insert(s.begin() + s.length(),'.');
	}
	int j = 0;
	for (; s[j] == '0' || s[j] == '.'; j++);
	if (j == s.length())
	{
		return 0;
	}else if (s.find('.') > j)
	{
		return s.find('.') - j;
	}else
	{
		return s.find('.') - j + 1;
	}
	
}

string getBase(int n, string s) {
	if (s.find('.') != string::npos)
	{
		s.erase(s.begin() + s.find('.'),s.begin() + s.find('.') + 1);
	}
	if (s[0] == '0')
	{
		int i = 1;
		for (; s[i] == '0'; i++);
		s.erase(s.begin(),s.begin() + i);
	}
	while (s.length() < n)
	{
		s.insert(s.end() ,'0');
	}
	s.erase(s.begin() + n, s.end());
	s.insert(s.begin(),'.');
	s.insert(s.begin(),'0');
	return s;
}

int main() {
	int n;
	string m1, m2;
	cin >> n >> m1 >> m2;

	string m1b, m2b;
	int m1p, m2p;

	m1b = getBase(n,m1);
	m2b = getBase(n,m2);

	m1p = getPow(m1);
	m2p = getPow(m2);

	if (m1b == m2b && m1p == m2p)
	{
		cout << "YES " << m1b << "*10^" << m1p << endl;
	}else
	{
		cout << "NO " << m1b << "*10^" << m1p << " " << m2b << "*10^" << m2p << endl;
	}


}
























//部分正确程序，使用了double导致位数不够
/*
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

string getBase(int n,double m) {
	if (m >= 1)
	{
		for (int i = 0; m >= 1; i++)
		{
			m = m / 10;
		}

	}else if (m < 1 && m > 0)
	{
		for (int i = 0; m < 0.1; i++)
		{
			m = m * 10;
		}
	}
	string s;
	s = to_string(m);
	s.erase(s.begin() + n + 2, s.end());
	return s;
}

int getPow(double m) {
	int i = 0;
	if (m >= 1)
	{
		for (; m >= 1; i++) {
			m = m / 10;
		}
	}
	else if (m < 1 && m > 0)
	{
		for (; m < 0.1; i--) 
		{
			m = m * 10;
		}
	}
	return i;
}

int main() {
	int n;
	double m1, m2;
	scanf("%d%lf%lf",&n,&m1,&m2);

	string m1b, m2b;
	int m1p, m2p;

	m1b = getBase(n,m1);
	m2b = getBase(n,m2);

	m1p = getPow(m1);
	m2p = getPow(m2);

	if (m1b == m2b && m1p == m2p)
	{
		printf("YES ");
		for (int i = 0; i < n + 2; i++)
		{
			printf("%c",m1b[i]);
		}
		printf("*10^%d",m1p);
	}else
	{
		printf("NO ");
		for (int i = 0; i < n + 2; i++)
		{
			printf("%c",m1b[i]);
		}
		printf("*10^%d ",m1p);
		for (int i = 0; i < n + 2; i++)
		{
			printf("%c",m2b[i]);
		}
		printf("*10^%d",m2p);
	}
}
*/