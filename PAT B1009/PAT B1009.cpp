#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    char s1[81];
    char s2[81][81];
    while (gets_s(s1))
    {
        int j = 0, k = 0;
        for (int i = 0; i < strlen(s1); i++)
        {
            if (s1[i] == ' ')
            {
                s2[j][k] = '\0';
                k = 0;
                j++;
            }
            else s2[j][k++] = s1[i];
        }
        s2[j][k] = '\0';
        for (int i = j; i >= 0; i--)
        {
            cout << s2[i];
            if(i != 0) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
