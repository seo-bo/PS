#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int cnt = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;
	vector<int>v(N);
	M *= K;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	for (auto& i : v)
	{
		if (M <= 0)
		{
			break;
		}
		cnt++;
		M -= i;
	}
	if (M > 0)
	{
		cout << "STRESS";
	}
	else
	{
		cout << cnt;
	}
	return 0;
}