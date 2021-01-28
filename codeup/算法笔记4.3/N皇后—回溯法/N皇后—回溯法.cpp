#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 11;
int n, P[maxn], sum = 0;
bool hashTable[maxn] = { false };
void generateP(int index)
{
	if (index == n + 1)
	{
		sum++;
		return;
	}
	for (int x = 1; x <= n; x++)
	{
		if (hashTable[x] == false)
		{
			bool flag = true;
			for (int i = 1; i < index; i++)
			{
				if (abs(index - i) == abs(x - P[i]))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				P[index] = x;
				hashTable[x] = true;
				generateP(index + 1);
				hashTable[x] = false;
			}
		}
	}
}
int main()
{
	n = 8;
	generateP(1);
	cout << sum << endl;
	return 0;
}
