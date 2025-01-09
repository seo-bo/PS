#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, k = 0;
		cin >> n >> k;
		int pivot = 0, cnt = 0;
		vector<int>v(n);
		for (auto& i : v)
		{
			cin >> i;
			if (i >= k)
			{
				pivot += i;
			}
			else if (i == 0 && pivot > 0)
			{
				pivot--;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
