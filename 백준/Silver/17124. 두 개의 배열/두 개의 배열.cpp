#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		ll sum = 0;
		vector<ll>A(n);
		vector<ll>B(m);
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> B[i];
		}
		sort(B.begin(), B.end());
		for (auto& i : A)
		{
			int idx = lower_bound(B.begin(), B.end(), i) - B.begin();
			if (idx < m)
			{
				if (llabs(B[idx] - i) < llabs(B[max(0, idx - 1)] - i))
				{
					sum += B[idx];
				}
				else
				{
					sum += B[max(0, idx - 1)];
				}
			}
			else if (idx == m)
			{
				sum += B[m - 1];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}