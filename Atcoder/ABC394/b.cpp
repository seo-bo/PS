#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end(), [&](const string& a, const string& b)
		{
			return (int)a.size() < (int)b.size();
		});
	for (auto& i : v)
	{
		cout << i;
	}
	return 0;
}
