#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str1,str2;
    while((cin>>str1>>str2))
    {
        int i1,i2,m1,n1,m2,n2;
        m1=m2=0;
        while((n1=str1.find(",",m1))!= string::npos)
        {
            m1=n1+1;
            str1.erase(n1,1);
        }
        while((n2=str2.find(",",m2))!= string::npos)
        {
            m2=n2+1;
            str2.erase(n2,1);
        }
        i1=stoi(str1);
        i2=stoi(str2);
        cout<<i1+i2<<endl;
    }


    return 0;
}
