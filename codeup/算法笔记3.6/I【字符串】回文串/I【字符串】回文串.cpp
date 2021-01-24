#include <iostream>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        bool flag = true;
        for (int i = 0; i < s.size()/2; i++)
        {
            if (s[i] == s[s.size() - i - 1]) continue;
            else
            {
                cout << "NO"<<endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
    }
    return 0;
}
