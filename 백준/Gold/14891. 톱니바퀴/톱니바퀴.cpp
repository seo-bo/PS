#include <bits/stdc++.h>
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
	vector<deque<int>>dq(4);
	for (int i = 0; i < 4; ++i)
	{
		string str;
		cin >> str;
		for (auto& k : str)
		{
			dq[i].push_back(k - '0');
		}
	}
	int n = 0;
	cin >> n;
	while (n--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a--;
		vector<int>r(4, 0);
		r[a] = b;
		for (int i = a; i > 0; --i)
		{
			if (dq[i][6] != dq[i - 1][2])
			{
				r[i - 1] = -r[i];
			}
			else
			{
				break;
			}
		}
		for (int i = a; i < 3; ++i)
		{
			if (dq[i][2] != dq[i + 1][6])
			{
				r[i + 1] = -r[i];
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (r[i] == 1)
			{
				dq[i].push_front(dq[i].back());
				dq[i].pop_back();
			}
			else if (r[i] == -1)
			{
				dq[i].push_back(dq[i].front());
				dq[i].pop_front();
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		ans += dq[i][0] * (1 << i);
	}
	cout << ans;
	return 0;
}