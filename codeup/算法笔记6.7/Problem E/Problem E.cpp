#include <iostream>
#include <stack>
#include <string>
using namespace std;

int judge(char c)
{
    if (c == '(' || c == ')') return 1;
    else if (c == '{' || c == '}') return 2;
    else if (c == '[' || c == ']') return 3;
    else return 0;
}

bool left(char c)
{
    if (c == '(' || c == '[' || c == '{') return true;
    else return false;
}

int main()
{
    
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        stack<char> sk;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (judge(s[i]) && left(s[i]))
            {
                sk.push(s[i]);
            }
            else if (judge(s[i]) && !left(s[i]))
            {
                char temp;
                if (!sk.empty())
                {
                    temp = sk.top();
                    sk.pop();
                    if (judge(s[i]) == judge(temp)) continue;
                    else
                    {
                        flag = false;
                    }
                }
                else
                {
                    flag = false;
                }
                
            }
        }
        if (!sk.empty())flag = false;
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}