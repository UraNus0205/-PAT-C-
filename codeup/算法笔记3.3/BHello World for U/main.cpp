#include <iostream>

using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        int N = s.size();
        int n1,n2,n3;
        n1=n3=(N+2)/3;
        n2=N+2-n1-n3;
        for(int i=0;i<n3;i++)
        {
            if(i!=n3-1)
            {
                for(int j=0;j<n2;j++)
                {
                    if(j==0) cout<<s[i+j];
                    else if(j==n2-1) cout<<s[N-1-i];
                    else cout<<" ";
                }
                cout<<endl;
            }
            else
            {
                for(int j=0;j<n2;j++)
                {
                    cout<<s[j+n3-1];
                }
                cout<<endl;
            }
        }
    }

    return 0;
}
