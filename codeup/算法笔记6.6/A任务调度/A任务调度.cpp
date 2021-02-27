#include <iostream>
#include <queue>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

struct task {
    string s;
    int x;
    friend bool operator <(task t1, task t2)
    {
        return t1.x > t2.x;
    }
}t;

int main()
{
    map<string, bool> hash;
    priority_queue<task> q;
    int n, k;
    string s, word;
    while (cin >> n)
    {
        k = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>s;
            for (int j = 0; j < s.size(); j++)
            {

                if (isalnum(s[j]))
                {
                    word += s[j];
                }
                else
                {
                    word.clear();
                }
                if (!word.empty() && !isalnum(s[j + 1]))
                {
                    if (word == "NULL") continue;
                    if (hash[word] == false)
                    {
                        hash[word] = true;
                        t.s = word;
                        t.x = k++;
                        q.push(t);
                    }
                }
            }
        }
        cout << q.top().s;
        q.pop();
        while (!q.empty()) {
            cout << " " << q.top().s;
            q.pop();
        }
        cout << endl;
    }
    
    
    return 0;
}