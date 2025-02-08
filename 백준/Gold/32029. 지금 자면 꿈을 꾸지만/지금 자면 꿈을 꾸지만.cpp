#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) // 가장 텀이 많은 곳에서 자는게 아니고 그냥 전수 조사를 했어야;;
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, a = 0, b = 0, time = 0, ans = 0;
	cin >> n >> a >> b;
	vector<int>v(n + 1, 0);
	vector<pii>temp(n + 1); // 횟수, 시간
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; ++i)
	{
		temp[i] = temp[i - 1];
		if (time + a <= v[i])
		{
			time += a;
			temp[i].first++;
			temp[i].second = time;
		}
	}
	for (int i = 0; i <= n; ++i) // 초장부터 자는거 고려
	{
		for (int j = 0; j <= a - 1; ++j) // 잠자는 시간
		{
			int sum = temp[i].first;
			time = temp[i].second + j * b;
			for (int k = i + 1; k <= n; ++k)
			{
				if (a - j + time <= v[k])
				{
					time += a - j;
					sum++;
				}
			}
			ans = max(ans, sum);
		}
	}
	cout << ans;
	return 0;
}