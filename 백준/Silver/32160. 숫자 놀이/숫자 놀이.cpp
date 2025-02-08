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
	int n = 0;
	cin >> n;
	deque<int>dq;
	vector<pii>ans;
	for (int i = n - 1; i >= 1; --i)
	{
		if (i - 1 >= 1)
		{
			dq.push_front(1);
			ans.push_back(make_pair(i, i - 1));
			--i;
		}
		else
		{
			dq.push_front(1);
		}
	}
	while (dq.size() > 1)
	{
		deque<int>temp;
		int siz = dq.size();
		for (int i = siz - 1; i >= 0; --i)
		{
			if (i - 1 >= 0)
			{
				temp.push_front(abs(dq[i] - dq[i - 1]));
				ans.push_back(make_pair(dq[i], dq[i - 1]));
				--i;
			}
			else
			{
				temp.push_front(dq[i]);
			}
		}
		dq = temp;
	}
	ans.push_back(make_pair(n, dq[0]));
	cout << n - dq[0] << '\n';
	for (auto& [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}