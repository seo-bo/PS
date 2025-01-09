#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 종만북에서 배운 top-down?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>dp(n + 1, -1);
	/* 8 -> (1,2)(3,4,5)(6,7,8) <- 최적 부분 구조?
	   9 -> (1,2,3)(4,5,6)(7,8,9)
	   10 ->(1,2,3)(4,5,6)(7,8,9,10)
	   11 ->(1,2,3,4)(5,6,7)(8,9,10,11)*/
	function<int(int)> dfs = [&](int node)->int
		{
			if (dp[node] != -1)
			{
				return dp[node];
			}
			if (node <= 1)
			{
				return dp[node] = node;
			}
			int pivot = node - 3;
			return dp[node] = dfs(pivot / 2) + 1 + dfs((pivot + 1) / 2);
		};
	int ans = 0;
	/*각 분할 시도
	8 -> 0 6 / 0 5 / 1 4 / 2 3
	9 -> 0 7 / 0 6 / 1 5 / 2 4 / 3 3*/
	for (int i = 0; i < (n + 1) / 2; ++i)
	{
		int cnt = 1, left = max(0, i - 1), right = max(0, n - i - 2); // <- 일단 한놈 앉히기
		if (left >= 2) // 맨 왼쪽에 앉게하기
		{
			cnt++;
			left = max(0, left - 2);
		}
		if (right >= 2) // 맨 오른쪽에 앉게 하기
		{
			cnt++;
			right = max(0, right - 2);
		}
		ans = max(ans, dfs(left) + cnt + dfs(right));
	}
	cout << ans;
	return 0;
}