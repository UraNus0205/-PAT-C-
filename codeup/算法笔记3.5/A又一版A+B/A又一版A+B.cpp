#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    int m;
    while (cin>>m>>a>>b)
    {
        if (m == 0) break;
        int res[100];
        long long sum = a + b; int num = 0;
        do {
            res[num++] = sum % m;
            sum /= m;
        } while (sum);
        for (int i = num - 1; i >= 0; i--)
        {
            cout << res[i];
        }
        cout << endl;

    }
    return 0;
}

