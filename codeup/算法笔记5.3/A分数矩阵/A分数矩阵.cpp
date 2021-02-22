#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double n;
    while (cin >> n && n != 0)
    {
        double sum = 0;
        sum += n;
        double down = 2;
        for (int i = n; i > 1; i--)
        {
            sum += 1.0 / i * down;
            down = down + 2;
        }
        printf_s("%.2f\n", sum);
    }
    return 0;
}
/*
1
22
342
4642
58642
*/