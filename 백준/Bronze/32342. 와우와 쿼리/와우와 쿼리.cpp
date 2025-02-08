#include <bits/stdc++.h>
#include <unordered_set>
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
		string a;
		deque<char>dq;
		cin >> a;
		int ans = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if (dq.size() == 3)
			{
				if (dq[0] == 'W' && dq[1] == 'O' && dq[2] == 'W')
				{
					ans++;
				}
				dq.pop_front();
			}
			dq.push_back(a[i]);
		}
		if (dq.size() == 3 && dq[0] == 'W' && dq[1] == 'O' && dq[2] == 'W')
		{
			ans++;
			dq.pop_front();
		}
		cout << ans << '\n';
	}
	return 0;
}