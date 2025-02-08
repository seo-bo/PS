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
	int n = 0;
	cin >> n;
	int x = INT_MAX, y = INT_MAX, xx = INT_MIN, yy = INT_MIN;
	while (n--)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		x = min(x, a), y = min(y, b);
		xx = max(xx, c), yy = max(yy, d);
		cout << 2 * ((xx - x) + (yy - y)) << '\n';
	}
	return 0;
}