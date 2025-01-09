#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<ll>p;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			p.push_back(v[i] + v[j]);
		}
	}
	sort(p.begin(), p.end());
	for (int i = n - 1; i >= 0; --i) //차이 최소로
	{
		for (int j = 0; j < n; ++j)
		{
			if (binary_search(p.begin(), p.end(), v[i] - v[j]))
			{
				cout << v[i];
				return 0;
			}
		}
	}

	return 0;
}