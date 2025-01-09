#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int main(void) // 자고 일어나서 단조큐로도 짜보자
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, h = 0;
	cin >> n >> h;
	vector<ll>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](const int& a, const int& b)
		{
			return a > b;
		});
	int cnt = 0;
	for (int i = 0; i < n && h >0; ++i)
	{
		h -= v[i];
		cnt++;
	}
	cout << cnt;
	return 0;
}

