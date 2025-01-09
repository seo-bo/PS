#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	unordered_set<int>s = { 2,3,5,7,11,13,17,19 };
	cin.tie(0)->ios::sync_with_stdio(0);
	int _ = 0, __ = 0;
	cin >> _ >> __;
	double a = _ / 100.0, b = __ / 100.0;
	vector<vector<double>>dp1(19, vector<double>(19, 0)), dp2(19, vector<double>(19, 0));
	dp1[0][0] = dp2[0][0] = 1;
	for (int i = 1; i <= 18; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			dp1[i][j] = dp1[i - 1][j] * (1 - a);
			dp2[i][j] = dp2[i - 1][j] * (1 - b);
			if (j > 0)
			{
				dp1[i][j] += dp1[i - 1][j - 1] * a;
				dp2[i][j] += dp2[i - 1][j - 1] * b;
			}
		}
	}
	double ans = 0.0;
	for (int i = 0; i <= 18; ++i)
	{
		for (int j = 0; j <= 18; ++j)
		{
			if (s.find(i) != s.end() || s.find(j) != s.end())
			{
				ans += dp1[18][i] * dp2[18][j];
			}			
		}
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}