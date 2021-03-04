#include <iostream>
#include <string>
using namespace std;

struct stu {
	string num;
	int test;
}s[1010];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string num;
		int pre_, test_;
		cin >> num >> pre_ >> test_;
		s[pre_].num = num;
		s[pre_].test = test_;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		cout << s[a].num << " " << s[a].test << endl;
	}
	return 0;
}

