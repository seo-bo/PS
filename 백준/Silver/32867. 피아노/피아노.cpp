#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, pivot = 0, m = 0, ans = 0;
	cin >> n >> k;
	k--;
	cin >> pivot;
	m = pivot;
	for (int i = 1; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp > pivot)
		{
			if (pivot + k < temp)
			{
				ans++;
				pivot = m = temp;
				continue;
			}
		}
		else if (temp < pivot)
		{
			if (temp + k < m)
			{
				ans++;
				pivot = m = temp;
				continue;
			}
			pivot = temp;
		}
		m = max(m, temp);
	}
	cout << ans;
	return 0;
}