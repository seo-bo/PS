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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 0;
	cin >> T;
	while (T--) // 아니 왤케 어렵게 생각했지??..
	{
		ll n = 0, ans = 0;
		cin >> n;
		vector<string>v(2);
		cin >> v[0] >> v[1];
		for (int i = 0; i < n - 2; ++i)
		{
			if ((v[0][i] == 'x' && v[1][i] == '.') && (v[0][i + 1] == '.' && v[1][i + 1] == '.') && (v[0][i + 2] == 'x' && v[1][i + 2] == '.'))
			{
				ans++;
			}
			if ((v[1][i] == 'x' && v[0][i] == '.') && (v[1][i + 1] == '.' && v[0][i + 1] == '.') && (v[1][i + 2] == 'x' && v[0][i + 2] == '.'))
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
