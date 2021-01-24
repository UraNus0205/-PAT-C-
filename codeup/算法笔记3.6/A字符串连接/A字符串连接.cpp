#include <iostream>
using namespace std;
int main()
{
    char s1[210];
    char s2[210];
    while (cin >> s1 >> s2)
    {
        int i = 0, j = 0;
        while (s1[i] != '\0')
        {
            i++;
        }
        while (s2[j] != '\0')
        {
            j++;
        }
        int p = 0;
        for (int k = i; k <= i + j; k++)
        {
            s1[k] = s2[p++];
        }

        cout << s1 << endl;;
    }
    return 0;
}

