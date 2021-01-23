#include <iostream>

using namespace std;

int main()
{
    int h;
    while(cin>>h)
    {
        if(h>=1 && h<=1000)
        {
            for(int i=0;i<h;i++)
            {
                for(int j=0;j<(3*h-2);j++)
                {
                    if(j<2*h-2*i-2) cout<<" ";
                    else cout<<"*";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
