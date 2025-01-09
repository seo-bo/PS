#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--) // 오옹,,, 시간복잡도는 별로 차이 안나보이는데
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>mm(10, vector<int>(10, 0)); //(A, B), score
		for (int i = 0; i < m; ++i)
		{
			int v = 0, a = 0, b = 0;
			cin >> v >> a >> b;
			mm[a][b] += v;
		}
		ll ans = 0;
		unordered_map<ll, int>_;
		vector<int>temp(n);
		iota(temp.begin(), temp.end(), 1);
		do
		{
			ll sum = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = i + 1; j < n; ++j)
				{
					sum += mm[temp[i]][temp[j]];
				}
			}
			_[sum]++;
			ans = max(ans, sum);
		} while (next_permutation(temp.begin(), temp.end()));
		cout << ans << ' ' << _[ans] << '\n';
	}
	return 0;
}