#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, pivot = 0;
	vector<int>ans;
	cin >> n;
	for (int i = n / 2; i <= n; ++i)
	{
		vector<int>temp = { n,i };
		int idx = 1;
		while (1)
		{
			int target = temp[idx - 1] - temp[idx];
			if (target < 0)
			{
				break;
			}
			temp.push_back(target);
			idx++;
		}
		if (temp.size() > pivot)
		{
			pivot = temp.size();
			ans = temp;
		}
	}
	cout << pivot << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}