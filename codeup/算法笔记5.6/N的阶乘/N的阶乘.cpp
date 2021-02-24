#include <iostream>
#include <cstring>
using namespace std;

struct bign {
    int d[1000];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
bign mul(bign a, int b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++)
    {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}



void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
    {
        cout << a.d[i];
    }
    cout << endl;
}

bign change2(int x)
{
    bign a;
    while (x)
    {
        a.d[a.len++] = x % 10;
        x /= 10;
    }
    return a;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)cout << "1" << endl;
        else
        {
            bign a=change2(n);
            for (int i = 1; i < n; i++)
            {
                a = mul(a, i);
            }
            print(a);
            
        }
    }
    return 0;
}

