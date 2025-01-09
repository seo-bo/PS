#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<int>v(8);
	for (int i = 0; i < 8; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[i] = temp * 10;
	}
	vector<int>temp(8);
	vector<int>visited(8);
	int ans = INT_MAX;
	function<void(int)> dfs = [&](int depth)
		{
			if (depth == 8)
			{
				int t = 0;
				for (int i = 0; i < 2; ++i)
				{
					int pivot = i * 4;
					t = max(t, abs((temp[pivot] + temp[pivot + 1]) / 2 - (temp[pivot + 2] + temp[pivot + 3]) / 2));
				}
				ans = min(t, ans);
				return;
			}
			for (int i = 0; i < 8; ++i)
			{
				if (!visited[i])
				{
					visited[i] = true;
					temp[depth] = v[i];
					dfs(depth + 1);
					temp[depth] = 0;
					visited[i] = false;
				}
			}
		};
	dfs(0);
	//cout << ans << '\n';
	if (!ans)
	{
		cout << "1.0";
	}
	else if (ans < 10)
	{
		cout << "0.9" << 10 - ans;
	}
	else
	{
		if (ans % 10)
		{
			cout << "0." << 100 - ans;
		}
		else
		{
			cout << "0." << 10 - ans / 10;
		}
	}
	return 0;
}