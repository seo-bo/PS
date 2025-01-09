#include <bits/stdc++.h>
using namespace std;

bool make(vector<int>& a, int n) 
{
    if (a[0] > a[1] || a[n - 1] > a[n - 2])
    {
        return false;
    }
    for (int i = 1; i < n - 1; i++) 
    {
        int minp = min(a[i - 1], a[i + 1]);
        a[i - 1] -= minp;
        a[i] -= minp * 2;
        a[i + 1] -= minp;
        if (a[i] < 0)
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++) 
    {
        if (a[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int test;
    cin >> test;
    while (test--) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (make(a, n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
