#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 100100;
int prime[maxn], pNum = 0;
bool p[maxn] = { false };
bool isPrime(int n)
{
    if (n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
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
            for (int j = i + i; j < maxn; j = j + i)
                p[j] = true;
        }
    }
}

int main()
{
    find_prime();
    int m, n;
    while (cin >> m >> n)
    {
        int time = 0;
        for (int i = m - 1; i < n; i++)
        {
            time++;
            if (time % 10 != 0 && time != (n - m + 1))
            {
                cout << prime[i] << " ";
            }
            else
            {
                cout << prime[i] << endl;
            }
        }
    }
    return 0;
}
