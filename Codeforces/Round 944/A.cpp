#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int test = 0;
	cin >> test;
	while (test--)
	{
		vector<int>v;
		v.resize(2);
		cin >> v[0] >> v[1];
		sort(v.begin(), v.end());
		cout << v[0] << " " << v[1] << "\n";
	}
	return 0;
}
