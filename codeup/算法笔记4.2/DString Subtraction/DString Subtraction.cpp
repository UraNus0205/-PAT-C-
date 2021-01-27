#include<cstdio>
#include<map>
#include<iostream>
#include<string>
using namespace std;

int main() {
	
	string s1, s2;
	while (getline(cin, s1)&&getline(cin,s2))
	{
		map<char, int> mp;
		for (int i = 0; i < s2.size(); i++)
		{
			mp[s2[i]] = 1;
		}
		for (int i = 0; i < s1.size(); i++)
		{
			if (mp[s1[i]] == 0) cout << s1[i];
		}
		cout << endl;
	}
	return 0;
}