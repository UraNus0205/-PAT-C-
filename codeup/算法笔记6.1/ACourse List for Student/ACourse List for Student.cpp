#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> hash1[maxn];
int transform(char c[])
{
    int id = 0;
    for (int i = 0; i < 3; i++)
    {
        id = id * 26 + c[i] - 'A';
    }
    id = id * 10 + c[3]-'0';
    return id;
}

int main()
{
    vector<int>::iterator it;
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int j=0;j<k;j++)
    {
        int cno,cnt;
        cin >> cno >> cnt;
        for(int i=0;i<cnt;i++)
        {
            char sname[10];
            cin >> sname;
            hash1[transform(sname)].push_back(cno);
        }
    }
    for (int i = 0; i < n; i++)
    {
        char sname[10];
        cin >> sname;
        cout << sname << " " << hash1[transform(sname)].size();
        if (hash1[transform(sname)].size())
        {
            sort(hash1[transform(sname)].begin(), hash1[transform(sname)].end());
            for (it=hash1[transform(sname)].begin();it!=hash1[transform(sname)].end();it++)
            {
                cout << " " << *it;
            }
        }
        cout << endl;
    }
    return 0;
}
