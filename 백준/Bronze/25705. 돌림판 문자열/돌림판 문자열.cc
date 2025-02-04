#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, ans = 0, idx = 0;
	cin >> n;
	deque<char>base(n);
	vector<int>alp(27, 0);
	for (auto& i : base)
	{
		cin >> i;
		alp[i - 'a']++;
	}
	base.push_front(base.back());
	base.pop_back();
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		char a;
		cin >> a;
		if (!alp[a - 'a'])
		{
			cout << -1;
			return 0;
		}
		while (1)
		{
			idx = (idx + 1) % n;
			ans++;
			if (base[idx] == a)
			{
				break;
			}
		}
	}
	cout << ans;
	return 0;
}