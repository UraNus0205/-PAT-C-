#include <iostream>
using namespace std;
int chocolate(int n)
{
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else
    {
        return chocolate(n - 1) + chocolate(n - 2);
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        cout << chocolate(n) << endl;
    }
    return 0;
}

