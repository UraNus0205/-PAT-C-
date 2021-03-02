#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int k;
    cin >> k;
    long long a, b, c, res;
    bool flag;
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b >> c;
        res = a + b;
        
        if (a > 0 && b > 0 && res < 0)
        {
            flag = true;
        }
        else if (a < 0 && b < 0 && res >= 0)
        {
            flag = false;
        }
        else if (res > c) flag = true;
        else flag = false;
        if (flag)
        {
            cout << "Case #" << i << ": true" << endl;
        }
        else
        {
            cout << "Case #" << i << ": false" << endl;
        }
    }
    return 0;
}

