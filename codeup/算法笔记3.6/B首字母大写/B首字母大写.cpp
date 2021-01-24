#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        if (s[0] >= 'a' && s[0] <= 'z')s[0] -= 32;
        int n, m = 0;
        while (((n = s.find(' ', m)) != string::npos)|| ((n = s.find('\t', m)) != string::npos)|| ((n = s.find('\n', m)) != string::npos)|| ((n = s.find('\r', m)) != string::npos))
        {
            if (s[n + 1] >= 'a' && s[n + 1] <= 'z')
            {
                s[n + 1] -= 32;
            }
            m = n + 1;
        }
        cout << s << endl;
    }

    return 0;
}

