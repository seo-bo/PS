#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	if (!next_permutation(v.begin(), v.end()))
	{
		cout << -1;
	}
	else
	{
		for (auto& i : v)
		{
			cout << i << ' ';
		}
	}
	return 0;
}