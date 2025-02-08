#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int p = 0, ans = 0;
		cin >> p;
		vector<int>v(20);
		for (auto& i : v)
		{
			cin >> i;
		}
		for (int i = 0; i < 20; ++i)
		{
			for (int j = i; j < 20; ++j) // 삽입 정렬이랑 비슷하게
			{
				if (v[i] > v[j])
				{
					ans++;
				}
			}
		}
		cout << p << ' ' << ans << '\n';
	}
	return 0;
}