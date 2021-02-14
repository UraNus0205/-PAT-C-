#include <iostream>
typedef long long ll;


ll binaryPow1(ll a, ll b, ll m)//递归
{
    if (b == 0) return 1;
    else if (b % 2 == 1) return a * binaryPow1(a, b - 1, m) % m;
    else
    {
        ll mul = binaryPow1(a, b / 2, m);
        return mul * mul % m;
    }
}

ll binaryPow2(ll a, ll b, ll m)//迭代
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    return 0;
}

