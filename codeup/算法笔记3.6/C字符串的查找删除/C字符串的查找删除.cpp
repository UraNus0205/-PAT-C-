
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int k = 0;
    char s[10000], tar[10000],res[10000];
    gets_s(s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    while (scanf("%c",&tar[k])!=EOF)
    {
        res[k] = tar[k];
        if (tar[k] >= 'A' && tar[k] <= 'Z') tar[k] += 32;
        if (tar[k] == s[strlen(s) - 1])
        {
            int i = 0;
            int t = 0;
            for (i = k - strlen(s) + 1; i <= k; i++)
            {
                if (tar[i] != s[t++]) break;
            }
            if (i == k + 1) k = k - strlen(s) + 1;
            else k++;
        }
        else k++;
    }
    for (int i = 0; i < k; i++)
    {
        if(res[i]!=' ')printf("%c", res[i]);
    }
    printf("\n");
    return 0;
}

