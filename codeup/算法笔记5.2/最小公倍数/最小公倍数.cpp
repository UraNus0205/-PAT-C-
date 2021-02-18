#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m,a[10010];
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        int min = a[0];
        for (int i = 1; i < m; i++)
        {   
            min = min / gcd(min, a[i]) * a[i];
        }
        cout << min << endl;
    }
    return 0;
}


