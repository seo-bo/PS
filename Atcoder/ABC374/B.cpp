#include <bits/stdc++.h>
#include <unordered_set>
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
	string a, b;
	cin >> a >> b;
	int len = min(a.size(), b.size());
	int p = max(a.size(), b.size());
	int idx = 0;
	if (a == b)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == b[i])
		{
			idx++;
		}
		else
		{
			cout << idx + 1;
			return 0;
		}
	}
	cout << idx + 1;
	return 0;
}
