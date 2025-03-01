#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n + 1);
	vector<int>tran(n + 1);
	vector<int>rev(n + 1);
	iota(tran.begin(), tran.end(), 0);
	iota(rev.begin(), rev.end(), 0);
	iota(v.begin(), v.end(), 0);
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			tran[b] = rev[c];
		}
		else if (a == 2)
		{
			cin >> b >> c;
			swap(v[rev[b]], v[rev[c]]);
			swap(rev[b], rev[c]);
		}
		else
		{
			cin >> b;
			cout << v[tran[b]] << '\n';
		}
	}
	return 0;
}
