#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;

int main(void) // 스위핑?
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>cost;
	vector<int>cnt(1000001, 0);
	vector<ti>v;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (!cnt[a])
		{
			cost.push_back(a);
		}
		cnt[a]++;
		v.push_back(make_tuple(a, b, c));
	}
	sort(cost.begin(), cost.end());
	ll ans = 0;
	ans += cost.size();
	vector<pii>temp;
	for (auto& [_, a, b] : v)
	{
		auto it = lower_bound(cost.begin(), cost.end(), a);
		if (it == cost.end() || *it > b) // lower_bound를 했는데 조건을 만족못하면 일단 넣기
		{
			temp.push_back(make_pair(a, b));
		}
		else
		{
			auto jt = next(it);
			if (_ == *it && cnt[*it] == 1 && (jt == cost.end() || *jt > b)) // 만약 그 검이 _랑 같고, 크기가 유일하며, 조건을 만족하는 다음검이 없다면
			{
				ans++;
			}
		}
	}
	sort(temp.begin(), temp.end(), [&](const pii& a, const pii& b)
		{
			if (a.first == b.first)
			{
				return a.second > b.second;
			}
			return a.first < b.first;
		});
	int left = 0, right = 0;
	for (auto& [a, b] : temp)
	{
		int L = max(left, a), R = min(right, b);
		if (L > R)
		{
			left = a, right = b;
			ans++;
		}
		else
		{
			left = L, right = R;
		}
	}
	cout << ans;
	return 0;
}