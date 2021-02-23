#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 10010;
int prime[maxn], pNum = 0;
bool p[maxn] = { false };

struct factor {
    int x, cnt;
};

factor fac[10];

bool isPrime(int n)
{
    if (n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void find_prime()
{
    for (int i = 2; i < maxn; i++)
    {
        if (p[i] == false)
        {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i)
            {
                p[j] = true;
            }
        }
    }
}

int main()
{
    find_prime();
    int n, num = 0;
    cin >> n;
    if (n == 1) cout << "1=1";
    else
    {
        cout << n << '=';
        int sqr = (int)sqrt(1.0 * n);
        for (int i = 0; i < pNum && prime[i] <= sqr; i++)
        {
            if (n % prime[i] == 0)
            {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (n % prime[i] == 0)
                {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1) break;
        }
        if (n != 1)
        {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for (int i = 0; i < num; i++)
        {
            if (i > 0)cout << "*";
            cout << fac[i].x;
            if (fac[i].cnt > 1)
                cout << "^" << fac[i].cnt;
        }
    }
    return 0;
}


