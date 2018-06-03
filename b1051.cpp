//当实部或虚部其中一项为零时，要输出0.00
//注意浮点数的边界判断，不然会出现-0.00的情况!!!!
//当负数舍去后几位后依旧为负数！！！
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	double r1, p1, r2, p2;
	double a, b;
	scanf("%lf%lf%lf%lf", &r1, &p1, &r2, &p2);

	a = r1 * r2 * cos(p1 + p2);
	b = r1 * r2 * sin(p1 + p2);

	if (abs(a) < 0.01)
	{
		a = 0;
	}
	if (abs(b) < 0.01)
	{
		b = 0;
	}
	if (b >= 0)
	{
		printf("%.2f+%.2fi", a, b);
	}
	else if (b < 0.01)
	{
		printf("%.2f%.2fi", a, b);
	}

}