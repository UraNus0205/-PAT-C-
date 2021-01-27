#include <string>
#include <iostream>
#include <map>
bool check(char c)
{
	if (c >= 'A' && c <= 'Z')return true;
	if (c >= '0' && c <= '9')return true;
	if (c >= 'a' && c <= 'z')return true;
	else return false;
}
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		map<string, int> mp;
		int j = 0;
		while(j < s.size())
		{
			string word;
			while (j < s.size() && check(s[j]))
			{
				if (s[j] >= 'A' && s[j] <= 'Z')s[j] += 32;
				word += s[j++];
			}
			if (mp.find(word) == mp.end()) mp[word] = 1;
			else mp[word]++;
			while (j < s.size() && !check(s[j]))
			{
				j++;
			}
		}
		string ans;
		int max = 0;
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second > max)
			{
				ans = it->first;
				max = it->second;
			}
		}
		cout << ans << " " << max << endl;
	}
	return 0;
}
