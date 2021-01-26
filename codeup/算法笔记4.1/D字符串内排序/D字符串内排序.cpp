#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
    char c[201];
    while (gets_s(c))
    {
        sort(c, c + strlen(c));
        cout << c << endl;
    }
    
    return 0;
}
