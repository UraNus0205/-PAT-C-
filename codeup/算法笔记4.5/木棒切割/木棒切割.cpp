#include <iostream>
#include <algorithm>
using namespace std;

int sum(int A[], int n, int l)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num += A[i] / l;
    }
    return num;
}

int solve(int A[], int n, int k)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] < max)
            max = A[i];
    }
    int left = 1, right = max, mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (sum(A, n, mid) > k)
        {
            left = mid + 1;
        }
        else if (sum(A, n, mid) == k)
        {
            return mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int main()
{
    int n = 3, k = 7;
    int len[10010] = { 10, 24, 16 };
    sort(len, len + n);
    cout << "go"<<endl;
    int L = solve(len,n,k);
    cout << L;
    return 0;
}

