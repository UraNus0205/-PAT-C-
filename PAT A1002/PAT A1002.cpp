#include <iostream>

using namespace std;

const int maxn = 1010;
double mp[maxn] = { 0 };
int main()
{
    int time = 2;
    int n, sum = 0;
    while(time--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int key;
            double value;
            cin >> key >> value;
            if (mp[key] == 0) sum++;
            mp[key] += value;
            if (mp[key] == 0) sum--;
        }
    }
    cout << sum;
    for (int i = 1000; i >= 0; i--)
    {
        if (mp[i] != 0)
        {
            printf(" %d %.1lf", i, mp[i]);
        }
    }
    return 0;
}
