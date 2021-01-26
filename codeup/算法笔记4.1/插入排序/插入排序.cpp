#include <iostream>
using namespace std;
int main()
{
    int a[5] = { 3,2,5,1,7 };
    for (int i = 1; i < 5; i++)
    {
        int temp = a[i];
        int j = i;
        while (j > 0 && temp < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a[i];
    }
    return  0;
}
