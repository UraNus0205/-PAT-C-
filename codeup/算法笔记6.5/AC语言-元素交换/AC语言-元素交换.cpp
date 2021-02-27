#include <iostream>
using namespace std;

int a[10];
void max(int& temp, int& j)
{
    temp = INT_MIN;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] > temp)
        {
            temp = a[i];
            j = i;
        }
    }
}

void min(int& temp, int& j)
{
    temp = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] < temp)
        {
            temp = a[i];
            j = i;
        }
    }
}


int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    int mx, mn, temp, mxi, mni;
    min(mn,mni);
    temp = a[0];
    a[0] = a[mni];
    a[mni] = temp;
    max(mx,mxi);
    temp = a[9];
    a[9] = a[mxi];
    a[mxi] = temp;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)cout << a[i];
        else cout << " " << a[i];
    }
    return 0;
}
