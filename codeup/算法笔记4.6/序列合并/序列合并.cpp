#include <iostream>
using namespace std;

int merge(int A[], int B[], int C[], int n, int m)
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while (i < n)
    {
        C[k++] = A[i++];
    }
    while (j < m)
    {
        C[k++] = B[j++];
    }
    return k;//返回序列C的长度
}

int main()
{
    return 0;
}

