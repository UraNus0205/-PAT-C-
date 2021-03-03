#include <iostream>
using namespace std;
double a[1010] = { 0 };
double b[2010] = { 0 };
int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int key;
        double value;
        cin >> key >> value;
        a[key] += value;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int key;
        double value;
        cin >> key >> value;
        for (int j = 0; j <=1000; j++)
        {
            b[key + j] += value * a[j];
        }
    }
    
    int sum = 0;
    for (int i = 0; i <= 2000; i++)
    {
        if (b[i] != 0) sum++;
    }
    cout << sum;
    for (int i = 2000; i >= 0; i--)
    {
        if (b[i] != 0)
            printf(" %d %.1lf", i, b[i]);
    }
    cout << endl;
    return 0;
}
