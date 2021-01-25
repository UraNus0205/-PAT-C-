#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        char a[110], b[110];
        gets_s(a);
        gets_s(b);
        int la = strlen(a), lb = strlen(b);
        char res[110][110];
        int row = 0, col = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ') res[row][col++] = s[i];
            else {
                res[row++][col] = '\0';
                col = 0;
            }
        }
        res[row][col] = '\0';
        for (int i = 0; i <= row; i++)
        {
            
            if (strcmp(a, res[i]) == 0)
            {
                int j = 0;
                for (j = 0; j < lb; j++)
                {
                    res[i][j] = b[j];
                }
                res[i][j] = '\0';
            }
            
        }
        for (int i = 0; i <= row; i++)
        {
            cout << res[i];
            if (i != row) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}
