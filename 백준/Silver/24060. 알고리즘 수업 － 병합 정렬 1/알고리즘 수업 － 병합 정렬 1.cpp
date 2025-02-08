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
	int n = 0, k = 0, cnt = 0;
	cin >> n >> k;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	auto merge = [&](int start, int mid, int end)
		{
			vector<int>temp(end - start + 1, 0);
			int i = start, j = mid + 1, t = 0;
			while (i <= mid && j <= end)
			{
				if (v[i] <= v[j])
				{
					temp[t++] = v[i++];
				}
				else
				{
					temp[t++] = v[j++];
				}
			}
			while (i <= mid)
			{
				temp[t++] = v[i++];
			}
			while (j <= end)
			{
				temp[t++] = v[j++];
			}
			for (int z = 0; z < t; ++z)
			{
				v[start + z] = temp[z];
				k--;
				if (!k)
				{
					cout << temp[z];
					exit(0);
				}
			}
		};
	function<void(int, int)> merge_sort = [&](int start, int end)
		{
			if (start < end)
			{
				int mid = (start + end) / 2;
				merge_sort(start, mid);
				merge_sort(mid + 1, end);
				merge(start, mid, end);
			}
		};
	merge_sort(0, n - 1);
	cout << -1;
	return 0;
}