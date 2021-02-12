
#include <iostream>
using namespace std;
//A[]是严格递增序列，left为二分下界，right为二分上界，x为欲查询的数
//二分区间为左闭右闭的[left,right],传入的初值为[0,n-1]
int binarySearch1(int A[], int left, int right, int x)
{
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] == x) return mid;//找到x，返回下标
        else if (A[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

//A[]是严格递增序,x为欲查询的数，函数返回第一个大于等于x的元素的位置
//二分区间为左闭右闭的[left,right],传入的初值为[0,n]
int lower_bound(int A[], int left, int right, int x)
{
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] > x)
        {
            right = mid - 1;
        }
        else if (A[mid] == x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

//A[]是严格递增序,x为欲查询的数，函数返回第一个大于x的元素的位置
//二分区间为左闭右闭的[left,right],传入的初值为[0,n]
int upper_bound(int A[], int left, int right, int x)
{
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] > x)
        {
            right = mid;
        }
        else if (A[mid] == x)
        {
            left = mid + 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
//A[]是严格递增序,x为欲查询的数，函数返回第一个大于等于x的元素的位置
//二分区间为左开右闭的(left,right],传入的初值为[-1,n]
int upper_bound2(int A[], int left, int right, int x)
{
    int mid;
    while (left + 1 < right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] > x)
        {
            right = mid;
        }
        else if (A[mid] == x)
        {
            left = mid;
        }
        else
        {
            left = mid;
        }
    }
    return left + 1;
}

int main()
{
    const int n = 10;
    int A[n] = { 1,3,3,4,4,4,4,11,12,15 };
    cout << upper_bound2(A, -1, n, 15)<<endl;
    return 0;
}

