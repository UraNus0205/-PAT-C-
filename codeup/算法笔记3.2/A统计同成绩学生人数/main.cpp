#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int arr[n],grade,sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>grade;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==grade) sum++;
        }
        cout<<sum<<endl;
    }
}
