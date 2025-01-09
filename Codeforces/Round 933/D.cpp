#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--) 
    {
        int n, m, x;
        cin >> n >> m >> x;
        set<int> can_pos;
        can_pos.insert(x);
        for (int i = 0; i < m; i++) 
        {
            int ri;
            char ci;
            cin >> ri >> ci;
            set<int> new_pos;
            for (int i : can_pos) 
            {
                if (ci == '?' || ci == '0') 
                { 
                    new_pos.insert((i - 1 + ri) % n + 1);
                }
                if (ci == '?' || ci == '1') 
                { 
                    new_pos.insert((i - 1 - ri + n) % n + 1);
                }
            }
            can_pos = new_pos;
        }
        cout << can_pos.size() << "\n";
        for (int i : can_pos) 
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

