#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s[54];
    for (int i = 0; i < 13; i++)
    {
        s[i] = "S" + to_string(i + 1);
    }
    for (int i = 13; i < 26; i++)
    {
        s[i] = "H" + to_string(i - 12);
    }
    for (int i = 26; i < 39; i++)
    {
        s[i] = "C" + to_string(i - 25);
    }
    for (int i = 39; i < 52; i++)
    {
        s[i] = "D" + to_string(i - 38);
    }
    for (int i = 52; i < 54; i++)
    {
        s[i] = "J" + to_string(i - 51);
    }
    int k,a[55];
    cin >> k;
    for (int i = 0; i < 54; i++)
    {
        cin >> a[i];
    }
    string temp[54];
    while (k--)
    {
        
        for (int i = 0; i < 54; i++)
        {
            temp[i] = s[i];
        }
        for (int i = 0; i < 54; i++)
        {
            s[a[i] - 1] = temp[i];
        }
    }
    for (int i = 0; i < 54; i++)
    {
        if (i != 53)cout << s[i] << " ";
        else cout << s[i];
    }
    return 0;
}

