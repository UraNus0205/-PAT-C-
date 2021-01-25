#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int main()
{
    char s[4][30] = { {""} ,{""}, {""}, {""} };
    int m;
    cin >> m;
    getchar();
    while (m--)
    {
        int k = 0;
        char c[30];
        
        gets_s(c);
        for (int i = 3; i >=0; i--)
        {
            if (i != 0)
            {
                int j = 0;
                for (j = 0; j < strlen(s[i - 1]); j++)
                {
                    s[i][j] = s[i - 1][j];
                }
                s[i][j] = '\0';
            }
            else
            {
                int j = 0;
                for (j = 0; j < strlen(c); j++)
                {
                    s[i][j] = c[j];
                }
                s[i][j] = '\0';
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if(strlen(s[i]))cout << i + 1 << "=" << s[i];
            if (i != 3) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}
