#include <iostream>
#include <cstdio>
using namespace std;
const int maxN=100010;
int grade[maxN]={0};
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        grade[a]+=b;
    }
    int max_c=1,max_g=-1;
    for(int j=1;j<=n;j++)
    {
        if(grade[j]>max_g)
        {
            max_c=j;
            max_g=grade[j];
        }

    }
    cout<<max_c<<" "<<max_g;
    return 0;
}
