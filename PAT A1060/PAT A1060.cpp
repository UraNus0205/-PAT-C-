#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;

string deal(string s,int& e)
{
    int k = 0;
    while (s.length() > 0 && s[0] == '0')
    {
        s.erase(s.begin());
    }
    if (s[0] == '.')
    {
        s.erase(s.begin());
        while (s.length() > 0 && s[0] == '0')
        {
            s.erase(s.begin());
            e--;
        }
    }
    else
    {
        while (k < s.length() && s[k] != '.')
        {
            k++;
            e++;
        }
        if (k < s.length())
        {
            s.erase(s.begin() + k);
        }
    }
    if (s.length() == 0)
    {
        e = 0;
    }
    string res;
    k = 0;
    for (int i = 0; i < n; i++)
    {
        if (k < s.length()) res += s[k++];
        else res += '0';
    }
    return res;
}

int main()
{
    string a, b, a2, b2;
    cin >> n >> a >> b;
    int e1 = 0, e2 = 0;
    a2 = deal(a, e1);
    b2 = deal(b, e2);
    if (a2 == b2 && e1 == e2)   
    {
        cout << "YES 0." + a2 + "*10^" << e1 << endl;
    }
    else
    {
        cout << "NO 0." + a2 + "*10^" << e1 << " 0." + b2 + "*10^" << e2 << endl;
    }
    return 0;
}