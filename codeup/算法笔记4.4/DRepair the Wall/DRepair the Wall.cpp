#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
int blocks[610];

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int l, n;
	while (cin >> l >> n)
	{
		memset(blocks, 0, sizeof(blocks));
		for (int i = 0; i < n; i++)
		{
			cin >> blocks[i];
		}
		sort(blocks, blocks + n, cmp);
		int sum = 0, res = 0, i = 0;;
		for (i = 0; i < n; i++)
		{
			if (res + blocks[i] >= l)
			{
				sum++;
				break;
			}
			else
			{
				sum++;
				res += blocks[i];
			}
		}
		if (i == n)
		{
			cout << "impossible" << endl;
		}
		else
			cout << sum << endl;
	}
	return 0;
}
