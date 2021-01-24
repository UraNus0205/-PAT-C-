#include <iostream>
#include <string>
#include <cstdio>
using namespace std;	
int main()
{
	long a, b;
	string n;
	while (cin>>a>>n>>b)
	{
		string str[100];
		int m = 0;
		for (int i = 0; i < n.size(); i++)
		{
			if (n[i] <= '9') m = m * a + n[i] - '0';
			else if (n[i] >= 'A' && n[i] <= 'F') m = m * a + n[i] + 10 - 'A';
			else if (n[i] >= 'a' && n[i] <= 'f') m = m * a + n[i] + 10 - 'a';
		}
		if (m == 0)cout << "0";
		int k = 0;
		while (m) {
			if (m % b > 9) { str[k++] = 'A' + m % b - 10; }
			else str[k++] = '0' + m % b;
			m /= b;
		}
		for (int i = k - 1; i >= 0; i--)
		{
			cout << str[i];
		}
		cout << endl;
	}
	
    return 0;
}
