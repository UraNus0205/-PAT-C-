#include <iostream>
#include <algorithm>
using namespace std;
const int k = 210;
struct AA{
    int num;
    int n;
};

bool cmp(AA a, AA b)
{
    return a.num < b.num;
}
int solve(AA A[], int left, int right, int x)
{
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid].num > x)
        {
            right = mid - 1;
        }
        else if (A[mid].num == x)
        {
            return mid;
        }
        else if (A[mid].num < x)
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int m;
    while (cin >> m)
    {
        AA A[k];
        for (int i = 0; i < m; i++)
        {
            cin >> A[i].num;
            A[i].n = i;
        }
        sort(A, A + m, cmp);
        int x;
        cin >> x;
        if (solve(A, 0, m - 1, x) == -1) cout << "-1" << endl;
        else cout << A[solve(A, 0, m - 1, x)].n << endl;
    }
    return 0;
}

