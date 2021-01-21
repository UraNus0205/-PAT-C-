#include <iostream>
#include <string>
using namespace std;
class stu
{
public:
    string sno;
    string sname;
    string ssex;
    int age;
};
int main()
{
    int m,n;
    stu s[1010];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>s[i].sno>>s[i].sname>>s[i].ssex>>s[i].age;
        }
        cin>>m;
        string a[10010];
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<m;i++)
        {
            bool flag=false;
            for(int j=0;j<n;j++)
            {
                if(s[j].sno.compare(a[i])==0)
                {
                    cout<<s[j].sno<<" "<<s[j].sname<<" "<<s[j].ssex<<" "<<s[j].age<<endl;
                    flag=true;
                    break;
                }
            }
            if(!flag) cout<<"No Answer!"<<endl;
        }
    }
    return 0;
}
