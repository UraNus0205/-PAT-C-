#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    char c;
    while(cin>>n>>c)
    {
        if(n>=3 && n<=20)
        {
            double m = round(n/2.0);
            for(int i=0;i<m;i++)
            {
                if(i==0 || i==m-1)
                {
                    for(int j=0;j<n;j++)
                        cout<<c;
                }
                else
                {
                    for(int j=0;j<n;j++)
                    {
                        if(j==0 || j==n-1) cout<<c;
                        else cout<<" ";
                    }
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
