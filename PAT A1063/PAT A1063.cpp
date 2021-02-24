#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

set<int> st[51];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            st[i].insert(temp);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int no1, no2, cnt = 0;
        set<int>::iterator it;
        cin >> no1 >> no2;
        for (it = st[no1].begin(); it != st[no1].end(); it++)
        {
            if (st[no2].find(*it) != st[no2].end()) cnt++;
        }
        printf("%.1lf%%\n", (double)cnt*100/ (st[no1].size() + st[no2].size() - cnt));
    }
    return 0;
}