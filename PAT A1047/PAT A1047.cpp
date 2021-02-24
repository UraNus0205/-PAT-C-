#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char stu[40010];
vector<string> hash1[2510];
bool cmp(string a,string b)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}

int main()
{
    int n, k, c, num, course;
    char sname[5];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> sname;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> course;
            hash1[course].push_back(sname);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << i << " " << hash1[i].size() << endl;
        sort(hash1[i].begin(), hash1[i].end(),cmp);
        for (int j = 0; j < hash1[i].size(); j++)
        {
            cout << hash1[i][j] << endl;
        }
    }
    return 0;
}
