#include <iostream>
using namespace std;
const int maxn = 11;
int n, P[maxn];
bool hashTable[maxn] = { false };//P为当前排列，hashTable记录整数x是否已经在P中
void generateP(int index)
{
    if (index == n + 1)//递归边界，已经处理完排列的1~n位
    {
        for (int i = 1; i <= n; i++)
        {
            cout << P[i];
        }
        cout << endl;
        return;
    }
    for (int x = 1; x <= n; x++)//枚举1~n，试图将x插入P[index]
    {
        if (hashTable[x] == false)//如果x不在P[0]~P[index-1]中
        {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;//已经处理完P[index]为x的子问题,还原状态
        }
    }
}
int main()
{
    n = 3;
    generateP(1);
    return 0;
}

