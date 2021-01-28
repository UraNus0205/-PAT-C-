#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 11;
int n, P[maxn], sum = 0;
int ans[100] = { 0 };
bool hashTable[maxn] = { false };
void generateP(int index)
{
	if (index == n + 1)
	{
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (abs(i - j) == abs(P[i] - P[j]))
					flag = false;
			}
		}
		if (flag)
		{
			sum++;
			for (int i = 1; i <= n; i++)
			{
				ans[sum] += P[i] * pow(10, n - i);
			}

		}
		return;
	}
	for (int x = 1; x <= n; x++)
	{
		if (hashTable[x] == false)
		{
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}
int main()
{
	n = 8;
	generateP(1);
	int a, b;
	cin >> a;
	while (a--)
	{
		cin >> b;
		cout << ans[b] << endl;
	}
	return 0;
}
