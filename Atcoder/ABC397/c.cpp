#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	map<int, int>left, right;
	for (auto& i : v)
	{
		cin >> i;
		right[i]++;
	}
	int ans = right.size();
	for (int i = 0; i < n; ++i)
	{
		left[v[i]]++;
		if (--right[v[i]] == 0)
		{
			right.erase(v[i]);
		}
		ans = max(ans, (int)left.size() + (int)right.size());
	}
	cout << ans;
	return 0;
}
