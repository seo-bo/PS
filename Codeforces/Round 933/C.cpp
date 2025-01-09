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
        int n;
        string s;
        cin >> n >> s;
        int count = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (s[i] == 'p' && i + 2 < n && s[i + 1] == 'i' && s[i + 2] == 'e') 
            {
                count++;
                i += 2;
            }
            else if (s[i] == 'm' && i + 2 < n && s[i + 1] == 'a' && s[i + 2] == 'p') 
            {
                count++;
                i += 2;
            }
        }
        cout << count << "\n";
    }
    return 0;
}

