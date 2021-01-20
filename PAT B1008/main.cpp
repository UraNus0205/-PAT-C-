#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int gcd(int n,int m)
{
    int temp=n;
    while(n%m!=0)
    {
        n=m;
        m=temp%m;
        temp=n;
    }
    return m;
}

int main()
{
    int n,m;
    cin>>n>>m;
    m=m%n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int r=gcd(n,m);
    int temp;
    if(m!=0)
    {
        for(int i=n-m;i<n-m+r;i++)
        {
            temp=a[i];

        }
    }

    return 0;
}
/*
temp=4
4=2 5=3
2=0 3=1
0=temp 1=twmp
*/
