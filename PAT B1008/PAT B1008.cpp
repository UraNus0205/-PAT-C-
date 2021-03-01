#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int a[101];

int main()
{
    int n, m;
    cin >> n >> m;
    m = m % n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - m; i < 2 * n - m; i++)
    {
        if (i == n - m)cout << a[i % n];
        else cout << " " << a[i % n];
    }
    return 0;
}
//4 10