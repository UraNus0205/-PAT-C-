#include <iostream>

using namespace std;
const int maxn = 10010;
int a[10010];
//将数组A的[L1,R1]与[L2,R2]区间合并为有序区间(L2=R1+1)
void merge(int A[], int L1, int R1, int L2, int R2)
{
    int i = L1, j = L2;
    int temp[maxn], k = 0;
    while (i <= R1 && j <= R2)
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }
    while (i <= R1) temp[k++] = A[i++];
    while (j <= R2) temp[k++] = A[j++];
    for (int i = 0; i < k; i++)
    {
        A[L1 + i] = temp[i];
    }
}

void mergeSort(int A[], int left, int right)//递归
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}
/*
void mergeSort2(int A[])
{
    //step为组内元素个数，step/2为左子区间元素个数，等号可以不取
    for (int step = 2; step / 2 <= n; step *= 2)
    {
        //每step个元素一组，组内前step/2和后step/2个元素进行合并
        for (int i = 1; i <= n; i += step)
        {
            int mid = i + step / 2 - 1;//左子区间元素个数为step/2
            if (mid + 1 <= n)//右子区间存在元素则合并
            {
                //左子区间为[i,mid],右子区间为[mid+1,min(i+step-1,n)]
                merge(A, i, mid, mid + 1, min(i + step - i, n));
            }
        }
        //此处可以输出归并排序后的某一趟结束的序列
    }
}
*/
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
