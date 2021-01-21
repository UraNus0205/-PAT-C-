#include <iostream>

using namespace std;
const int maxn=210;
int arr[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        if(n>=1&&n<=200)
        {
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            int x,flag=false;
            cin>>x;
            for(int j=0;j<n;j++)
            {
                if(arr[j]==x)
                {
                    cout<<j<<endl;
                    flag=true;
                }
            }
            if(!flag) cout<<-1<<endl;
        }
    }
    return 0;
}
