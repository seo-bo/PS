#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, pp = 3600, _ = 0;
	cin >> n;
	vector<int>prefix(86401, 0);
	auto cal = [&]
		{
			int h = 0, m = 0, s = 0;
			char c;
			cin >> h >> c >> m >> c >> s;
			return h * 3600 + m * 60 + s;
		};
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> _;
		vector<int>time(2);
		for (int j = 0; j < 2; ++j)
		{
			time[j] = cal();
		}
		if (time[0] > time[1])
		{
			prefix[time[0]]++;
			prefix[0]++;
			prefix[time[1]]--;
		}
		else
		{
			prefix[time[0]]++;
			prefix[time[1]]--;
		}
	}
	for (int i = 1; i <= 86400; ++i)
	{
		prefix[i] += prefix[i - 1];
	}
	cin >> _;
	int term = cal();
	ll ans = 0, now = 0, left = 0, right = term - 1;
	for (int i = 0; i < term; ++i)
	{
		now += prefix[i];
	}
	ans = max(ans, now);
	while (right < 86400)
	{
		now -= prefix[left++];
		now += prefix[++right];
		ans = max(ans, now);
	}
	cout << ans;
	return 0;
}