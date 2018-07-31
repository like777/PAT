#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int nc, np;
	scanf("%d", &nc);

	int number;
	vector<int> coupon, _coupon, product, _product;
	for (int i = 0; i < nc; i++)
	{
		scanf("%d", &number);
		if (number >= 0)
		{
			coupon.push_back(number);
		}else
		{
			_coupon.push_back(number);
		}
	}
	sort(coupon.begin(), coupon.end(), cmp);
	sort(_coupon.begin(), _coupon.end());

	scanf("%d", &np);
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &number);
		if (number >= 0)
		{
			product.push_back(number);
		}else
		{
			_product.push_back(number);
		}
	}
	sort(product.begin(), product.end(), cmp);
	sort(_product.begin(), _product.end());

	int ans = 0;
	for (int i = 0; i < coupon.size() && i < product.size(); i++)
	{
		ans += coupon[i] * product[i];
	}

	for (int i = 0; i < _coupon.size() && i < _product.size(); i++)
	{
		ans += _coupon[i] * _product[i];
	}

	printf("%d", ans);

}