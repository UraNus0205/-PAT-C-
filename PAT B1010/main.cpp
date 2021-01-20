#include <iostream>

using namespace std;

int main()
{
    int a[1010]={0};
    int k,e,j=0,num=0;
    while(scanf("%d %d",&k,&e)!=EOF)
    {
        a[j++]=k;
        a[j++]=e;
    }

    for(int i=0;i<j;i=i+2)
    {
        a[i]=a[i]*a[i+1];
        a[i+1]--;
        if(a[i]!=0) num++;
    }
    int n=1;
    for(int i=0;i<j;i=i+2)
    {
        if(a[i]!=0)
        {
            cout<<a[i]<<" "<<a[i+1];
            if(n<num)
            {
                cout<<" ";
                n++;
            }
        }
    }
    if(n==0) cout<<"0 0";
    return 0;
}
