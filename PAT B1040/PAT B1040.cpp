#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10010;
const int MOD = 1000000007;

int leftNumP[maxn] = { 0 };

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (i > 0)
        {
            leftNumP[i] = leftNumP[i - 1];
        }
        if (str[i] == 'P')
        {
            leftNumP[i]++;
        }
    }
    int ans = 0, rightNumT = 0;
    for (int i = (int)str.size() - 1; i >= 0; i--)
    {
        if (str[i] == 'T')
        {
            rightNumT++;
        }
        else if (str[i] == 'A')
        {
            ans = (ans + leftNumP[i] * rightNumT) % MOD;
        }
    }
    cout << ans % MOD << endl;
    return 0;
}

