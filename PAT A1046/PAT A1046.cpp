#include <iostream>
#include <algorithm>
using namespace std;
int q[100100];
int dist[100100];
int main()
{
    int n, sum = 0;
    cin >> n;
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        sum += q[i];
        dist[i + 1] = sum;
    }
    int m;
    cin>>m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int d = dist[b] - dist[a];
        cout << min(d,sum-d) << endl;
    }
    return 0;
}

