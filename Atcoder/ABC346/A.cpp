#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll, int>v;
unordered_map<ll, int>result;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i)
    {
        cout << A[i] * A[i + 1];
        if (i < N - 2)
        {
            cout << " ";
        }
    }
    return 0;
}
