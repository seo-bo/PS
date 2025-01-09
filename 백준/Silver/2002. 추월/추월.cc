#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	unordered_map<string, int>mm;
	int n = 0, ans = 0;
	cin >> n;
	vector<int>out(n);
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		string a;
		cin >> a;
		mm[a] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		out[i] = mm[a];
	}
	int pivot = 1;
	for (int i = 0; i < n; ++i)
	{
		if (pivot != out[i])
		{
			visited[out[i]] = true;
			ans++;
		}
		else
		{
			visited[pivot] = true;
			for (int j = pivot + 1; j <= n; ++j)
			{
				if (!visited[j])
				{
					pivot = j;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}