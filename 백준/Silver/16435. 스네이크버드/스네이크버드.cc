#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, l = 0;
	cin >> n >> l;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		if (l < i)
		{
			break;
		}
		else
		{
			l++;
		}
	}
	cout << l;
	return 0;
}