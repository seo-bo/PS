#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
		cin >> a >> b >> c >> d >> e >> f;
		int ed = a | b | c | d | e | f;
		if (!ed)
		{
			break;
		}
		vector<pii> v = { {a * c,b * d},{b * d,a * c},{a * d,b * c},{b * c,a * d} };
		bool check = false;
		int ans = INT_MAX, pivot = a * b - 1;
		for (auto& [p1, p2] : v)
		{
			if (p1 <= e && p2 <= f)
			{
				check = true;
				ans = min(ans, pivot + (p1 != e) + (p2 != f));
			}
		}
		if(!check)
		{
			cout << "The paper is too small.\n";
		}
		else
		{
			cout << "The minimum number of cuts is " << ans << ".\n";
		}
	}
	return 0;
}