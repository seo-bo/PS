#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<int>v(m), s;
	for (int i = 0; i < m; ++i)
	{
		cin >> v[i];
		while (!s.empty() && v[s.back()] <= v[i])
		{
			int mid = s.back();
			s.pop_back();
			if (s.empty())
			{
				break;
			}
			int left = s.back(), w = i - left - 1, h = min(v[left], v[i]) - v[mid];
			ans += w * h;
		}
		s.push_back(i);
	}
	cout << ans;
	return 0;
}