#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct moon {
	double store;
	double sell;//总价
	double price;//单价
}moons[1010];
bool cmp(moon a, moon b)
{
	return a.price > b.price;
}
int main()
{
	int n;
	double d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> moons[i].store;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> moons[i].sell;
		moons[i].price = moons[i].sell / moons[i].store;
	}
	sort(moons, moons + n, cmp);
	double ans=0;
	for (int i = 0; i < n; i++)
	{
		if (moons[i].store <= d)
		{
			d -= moons[i].store;
			ans += moons[i].sell;
		}
		else
		{
			ans += moons[i].price * d;
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}


