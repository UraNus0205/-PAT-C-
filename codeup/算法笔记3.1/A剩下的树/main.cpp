#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=10010;

int main()
{
    int l,m;
    int sum;
    int a[MAX];
    while(scanf("%d %d",&l,&m)!=EOF)
    {
        sum=0;

        for(int i=0;i<=l;i++) a[i]=1;
        if(l==0 || m==0) break;
        while(m--)
        {
            int c,b;
            scanf("%d %d",&c,&b);
            for(int i=c;i<=b;i++)
            {
                a[i]=0;
            }
        }
        for(int i=0;i<=l;i++)
        {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
