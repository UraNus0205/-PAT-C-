#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n >= 1 && n <= 50)
        {
            for (int i = 0; i < n ; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << " ";
                }
                for (int j = i; j < 2 * n - 1 - i; j++)
                {
                    if ((j+i) % 2 == 0)cout << "*";
                    else cout << " ";
                }
                cout << endl;
            }
            for (int i = n-2; i >= 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << " ";
                }
                for (int j = i; j < 2 * n - 1 - i; j++)
                {
                    if ((j + i) % 2 == 0)cout << "*";
                    else cout << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}

