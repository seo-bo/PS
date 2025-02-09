#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(3);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	if (v[0] * v[1] == v[2])
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
