#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, k = 0, ans = 0;
	cin >> n >> m >> k;
	vector<int>A = { 0,n }, B = { 0,m };
	while (k--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a ? A.push_back(b) : B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < A.size() - 1; ++i)
	{
		for (int j = 0; j < B.size() - 1; ++j)
		{
			ans = max(ans, (A[i + 1] - A[i]) * (B[j + 1] - B[j]));
		}
	}
	cout << ans;
	return 0;
}
