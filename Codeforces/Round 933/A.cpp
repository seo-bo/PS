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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> leftPocket(n), rightPocket(m);

        for (int i = 0; i < n; i++) 
        {
            cin >> leftPocket[i];
        }

        for (int i = 0; i < m; i++) 
        {
            cin >> rightPocket[i];
        }
        sort(leftPocket.begin(), leftPocket.end());
        sort(rightPocket.begin(), rightPocket.end());
        int count = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (leftPocket[i] + rightPocket[j] <= k) 
                {
                    count++;
                }
                else 
                {
                    break;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}
