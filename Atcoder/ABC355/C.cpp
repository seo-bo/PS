#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, T = 0;
	cin >> N >> T;
	vector<int>row(N, 0), col(N, 0);
	int cnt1 = 0, cnt2 = 0;
	vector<vector<bool>>mark(N, vector<bool>(N, false));
	for (int i = 1; i <= T; ++i)
	{
		int A = 0;
		cin >> A;
		int r = (A - 1) / N, c = (A - 1) % N;
		mark[r][c] = true;
		row[r]++;
		col[c]++;
		if (r == c)
		{
			cnt1++;
		}
		if (r + c == N - 1)
		{
			cnt2++;
		}
		if (row[r] == N || col[c] == N || cnt1 == N || cnt2 == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
