#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a = 0, b = 0, m = 0;
	cin >> a >> b >> m;
	vector<int>v(m);
	for (auto& i : v)
	{
		cin >> i;
	}
	reverse(v.begin(), v.end());
	int pivot = 0, shift = 1;
	for (int i = 0; i < m; ++i)
	{
		pivot += v[i] * shift;
		shift *= a;
	}
	vector<int>ans;
	while (pivot)
	{
		ans.push_back(pivot % b);
		pivot /= b;
	}
	reverse(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}