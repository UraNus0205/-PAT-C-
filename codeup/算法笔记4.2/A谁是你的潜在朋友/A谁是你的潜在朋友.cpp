#include <iostream>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n)
	{
		int fre[201] = { 0 }, ipt[202] = { 0 };
		cin >> m;
		for(int i=0;i<n;i++)
		{
			cin >> ipt[i];
			fre[ipt[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (fre[ipt[i]] == 1) cout << "BeiJu" << endl;
			else  cout << fre[ipt[i]]-1 << endl;
		}
	}
	
	return 0; 
}

