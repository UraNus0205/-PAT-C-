#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> a1;
    vector<int> a2;
    vector<int> a3;
    vector<int> a4;
    vector<int> a5;
    int n,code;
    cin>>n;
    int *p = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(int i=0;i<n;++i)
    {
        if(p[i]%10==0) a1.push_back(p[i]);
        if(p[i]%5==1) a2.push_back(p[i]);
        if(p[i]%5==2) a3.push_back(p[i]);
        if(p[i]%5==3) a4.push_back(p[i]);
        if(p[i]%5==4) a5.push_back(p[i]);
    }
    int sum_1=0,sum_2=0;
    double sum_4=0;
    for(int i=0;i<a1.size();i++)
    {
        sum_1+=a1[i];
    }
    for(int i=0;i<a2.size();i++)
    {
        sum_2+=pow(-1,i)*a2[i];
    }
    for(int i=0;i<a4.size();i++)
    {
        sum_4+=a4[i];
    }

    if(a1.size()==0) cout<<"N ";
    else cout<<sum_1<<" ";
    if(a2.size()==0) cout<<"N ";
    else cout<<sum_2<<" ";
    if(a3.size()==0) cout<<"N ";
    else cout<<a3.size()<<" ";
    if(a4.size()==0) cout<<"N ";
    else printf("%.1f ",sum_4/a4.size());
    if(a5.size()==0) cout<<"N";
    else cout<<*max_element(a5.begin(),a5.end());
    delete[] p;
    return 0;
}
