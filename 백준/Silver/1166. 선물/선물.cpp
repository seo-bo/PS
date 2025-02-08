#include <bits/stdc++.h>
#include <unordered_map>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N = 0, L = 0, W = 0, H = 0;
	cin >> N >> L >> W >> H;
	lb low = 0, high = INF;
	for (int i = 1; i <= sqrt(INF); ++i) // 이분탐색은 최대 log2
	{
		lb mid = (low + high) / 2;
		if ((ll)(L / mid) * (ll)(W / mid) * (ll)(H / mid) < N)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	cout << fixed << setprecision(15) << low;
	return 0;
}