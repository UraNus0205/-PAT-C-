#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool cmp1(int a, int b)
{
    return a > b;//递减排序
}

bool cmp2(int a, int b)
{
    return a < b;//递增排序
}

void to_array(int n, int num[])
{
    for (int i = 0; i < 4; i++)
    {
        num[i] = n % 10;
        n /= 10;
    }
}

int to_num(int num[])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum * 10;
        sum += num[i];
    }
    return sum;
}


int main()
{
    int n, MIN, MAX;
    cin >> n;
    int a[5];
    while (true)
    {
        to_array(n, a);
        sort(a, a + 4,cmp1);
        MAX = to_num(a);
        sort(a, a + 4,cmp2);
        MIN = to_num(a);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n",MAX,MIN,n);
        if (n == 0 || n == 6174) break;
    }
    return 0;
}

