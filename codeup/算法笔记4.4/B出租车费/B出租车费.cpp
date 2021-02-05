#include <iostream>

using namespace std;
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        double res = 0;
        if (n <= 4) res = 10;
        else if (n > 4 && n <= 8) res = 10 + (n - 4) * 2;
        else if (n > 8)
        {
            while (n > 8)
            {
                res += 18;
                n -= 8;
            }
            if (n <= 4) res += 2.4 * n;
            if (n > 4 && n <= 8) res += 10 + 2 * (n - 4);
        }
        cout << res << endl;
    }
    return 0;
}
