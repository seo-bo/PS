#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, p = 0, m = 0, num = 0;
	cin >> n >> k >> p >> m;
	vector<int>used(k + 1, -300000), cnt(k + 1, 0), ans;
	for (int i = 0; i < m; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (i - used[temp] < p)
		{
			cout << "impossible";
			return 0;
		}
		ans.push_back(temp);
		used[temp] = i;
		cnt[temp]++;
	}
	int count = -1, idx = m;
	while (ans.size() < n)
	{
		if (num == 0)
		{
			count++;
			num = 1;
		}
		if (cnt[num] > count)
		{
			num = (num + 1) % (k + 1);
			continue;
		}
		if (idx - used[num] < p)
		{
			cout << "impossible";
			return 0;
		}
		ans.push_back(num);
		used[num] = idx++;
		cnt[num]++;
		num = (num + 1) % (k + 1);
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}