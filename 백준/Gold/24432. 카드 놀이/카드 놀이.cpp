#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, k = 0;
		ll bma = 0, bmi = 0, mini = 0, maxi = 0;
		cin >> n >> m >> k;
		unordered_set<ll>visited;
		vector<ll>A, B;
		vector<ll>v1(n), v2(m);
		for (auto& i : v1)
		{
			cin >> i;
		}
		for (auto& i : v2)
		{
			cin >> i;
		}
		function<void(int, int, int, ll, vector<ll>&, vector<ll>&, bool)> dfs = [&](int depth, int end, int start, ll sum, vector<ll>& ve, vector<ll>& v, bool check)
			{
				if (depth == k)
				{
					bma = max(bma, sum), bmi = min(bmi, sum);
					if (visited.find(sum) == visited.end())
					{
						if (check)
						{
							auto it = lower_bound(A.begin(), A.end(), sum);
							if (it != A.end())
							{
								mini = min(mini, abs(sum - (*it)));
								auto itt = it;
								itt++;
								if (itt != A.end())
								{
									mini = min(mini, abs(sum - (*it)));
								}
							}
							if (it != A.begin())
							{
								it--;
								mini = min(mini, abs(sum - (*it)));
							}
						}
						else
						{
							ve.push_back(sum);
							visited.insert(sum);
						}
					}
					return;
				}
				for (int i = start; i < end; ++i)
				{
					dfs(depth + 1, end, i + 1, sum + v[i], ve, v, check);
				}
			};
		dfs(0, n, 0, 0LL, A, v1, false);
		sort(A.begin(), A.end());
		unordered_set<ll>().swap(visited);
		bma = LLONG_MIN, bmi = LLONG_MAX, mini = LLONG_MAX, maxi = LLONG_MIN;
		dfs(0, m, 0, 0LL, B, v2, true);
		cout << mini << ' ' << max(abs(bma - A.front()), abs(bmi - A.back())) << '\n';
	}
	return 0;
}