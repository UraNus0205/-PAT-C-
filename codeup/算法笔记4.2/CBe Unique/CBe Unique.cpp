
#include <iostream>
using namespace std;
int main()
{
	
	int n;
	while (cin >> n)
	{
		if (n > 0 && n <= 1e5)
		{
			int hash[10010] = { 0 };
			int a[100010] = { 0 };//记载输入顺序
			int max = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
				if (a[i] > max) max = a[i];
				hash[a[i]]++;
			}
			bool flag = false;
			for (int j = 0; j < n; j++)
			{
				if (hash[a[j]] == 1)
				{
					cout << a[j] << endl;
					flag = true;
					break;
				}
			}
			if (!flag) cout << "None" << endl;
		}
	}
	return 0;
}
