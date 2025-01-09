#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N = 0, M = 0;
	cin >> N >> M;
	vector<pair<ll, ll>>v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)
		{
			lb A = ((lb)(a.second) / (lb)(a.first));
			lb B = ((lb)(b.second) / (lb)(b.first));
			return A > B;
		});
	ll up = 0, down = 1, sum = 0;
	for (auto& i : v)
	{
		if (!M)
		{
			break;
		}
		if (i.first <= M)
		{
			sum += i.second;
			M -= i.first;
		}
		else if (i.first > M)
		{
			up = i.second * M;
			down = i.first;
			break;
		}
	}
	up += sum * down;
	ll g = gcd(up, down);
	up /= g;
	down /= g;
	cout << up << "/" << down;
	return 0;
}
