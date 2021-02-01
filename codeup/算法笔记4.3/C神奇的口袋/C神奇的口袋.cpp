#include <iostream>
using namespace std;
const int maxn = 21;
int p[maxn];
int f(int num, int i)
{
    if (num == 0)  return 1;
    if (i == 0) return 0;
    return f(num - p[i], i - 1) + f(num, i - 1);
}
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        cout << f(40, n) << endl;
    }
    return 0;
}

