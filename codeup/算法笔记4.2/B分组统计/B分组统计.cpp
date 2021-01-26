#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int hash[2011][2011];
    int fst[101];
    int m;
    cin >> m;
    while (m--)
    {
        int n;
        cin >> n;
        memset(hash, 0, sizeof(hash));
        memset(fst, 0, sizeof(fst));
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> fst[i];
            if (fst[i] > max) max = fst[i];
            hash[0][fst[i]] = 1;
        }
        int max_group=0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            hash[x][fst[i]]++;
            if (x > max_group) max_group = x;
            hash[x][0] = 1;
        }
        for (int i = 0; i <= max_group; i++)
        {
            if (hash[i][0] == 0) continue;
            cout << i << "={";
            for (int j = 0; j <= max; j++)
            {
                if (hash[0][j] == 0) continue;
                cout << j <<"="<< hash[i][j];
                if (j != max) cout << ",";
            }
            cout << "}" << endl;
        }
        
    }
    return 0;
}

