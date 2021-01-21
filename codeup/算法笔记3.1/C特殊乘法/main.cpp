#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int arr1[10],arr2[10];
        for(int i=0;i<10;i++)
        {
            arr1[i]=0;
        }
        int i=0,j=0;
        while(a)
        {
            int count=1;
            int temp=a;
            while(abs(temp)>=10)
            {
                temp=temp/10;
                count++;
            }
            arr1[i++]=temp;
            a=a-pow(10,count-1)*temp;
        }
        while(b)
        {
            int count=1;
            int temp=b;
            while(abs(temp)>=10)
            {
                temp=temp/10;
                count++;
            }
            arr2[j++]=temp;
            b=b-pow(10,count-1)*temp;
        }
        int sum=0;
        for(int p=0;p<i;p++)
        {
            for(int q=0;q<j;q++)
            {
                sum+=arr1[p]*arr2[q];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
