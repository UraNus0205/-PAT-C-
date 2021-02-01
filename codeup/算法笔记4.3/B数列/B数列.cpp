#include <iostream>
using namespace std;
int F(int n)
{
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    else return F(n - 1) + F(n - 2);
}
int main()
{
    int m, n;
    cin >> m;
    while (m--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n -1 - i; j++)
            {
                cout << "  ";
            }
            int k = 0;
            for (int j = n - 1 - i; j < n + i; j++)
            {
                cout << F(k++)<<" ";
            }
            cout << endl;
        }
    }
    return 0;
}

