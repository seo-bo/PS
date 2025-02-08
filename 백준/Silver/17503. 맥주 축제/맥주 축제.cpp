#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N = 0, M = 0, K = 0;
	cin >> N >> M >> K;
	ll s = 0, c = 0;
	vector < pair<ll, ll>>v(K);
	for (int i = 0; i < K; ++i) // first 선호도, second 도수
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first > b.first;
		});
	for (auto& i : v)
	{
		if (c == N)
		{
			break;
		}
		s += i.first;
		c++;
	}
	if (s < M)
	{
		cout << -1;
		return 0;
	}
	ll left = 0, right = LLONG_MAX;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll sum = 0, cnt = 0;
		for (auto& i : v)
		{
			if (cnt == N)
			{
				break;
			}
			if (mid >= i.second)
			{
				sum += i.first;
				cnt++;
			}
		}
		if (sum >= M && cnt == N)
		{
			right = mid - 1;
		}
		else 
		{
			left = mid + 1;
		}
	}
	cout << left;
	return 0;
}
