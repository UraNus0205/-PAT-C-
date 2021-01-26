#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct stu
{
    string sno;
    int grade;
    int location_num;
    int location_rank;
};
bool cmp(stu s1, stu s2)
{
    if (s1.grade != s2.grade)
        return s1.grade > s2.grade;
    else return s1.sno.compare(s2.sno) < 0;
}
int main()
{
    int n, k;
    cin >> n;
    stu a[30001];
    int i, j;
    int num = 0;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        for (j = 0; j < k; j++)
        {
            cin >> a[num].sno >> a[num].grade;
            a[num++].location_num = i + 1;
        }
        sort(a + num - k, a + num, cmp);
        a[num - k].location_rank = 1;
        for (j = num - k + 1; j < num; j++)
        {
            if (a[j].grade == a[j - 1].grade)
                a[j].location_rank = a[j - 1].location_rank;
            else a[j].location_rank = j - num + k + 1;
        }
    }
    cout << num << endl;
    sort(a, a + num, cmp);
    int r = 1;
    for (i = 0; i < num; i++)
    {
        if (i > 0 && a[i].grade != a[i - 1].grade)
            r = i + 1;
        cout << a[i].sno << " " << r << " " << a[i].location_num << " " << a[i].location_rank << endl;
    }

    return 0;
}

