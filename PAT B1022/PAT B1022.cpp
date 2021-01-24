
#include <iostream>
using namespace std;
int main()
{
    int a, b, d;
    while (cin >> a >> b >> d)
    {
        if (a >= 0 && b >= 0 && d > 1 && d <= 10)
        {
            int res[31], i = 0;
            int c = a + b;
            int temp;
            do {
                res[i++] = c % d;
                c = c / d;
            } while (c);
            for (int j = i - 1; j >= 0; j--)
            {
                cout << res[j];
            }
            cout << endl;
        }
    }
    return 0;
}
