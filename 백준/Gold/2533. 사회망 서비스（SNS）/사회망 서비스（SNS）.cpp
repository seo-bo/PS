#include <bits/stdc++.h>
using namespace std;

vector<int>graph[1000001];
int visited[1000001] = { 0, };
int dp[1000001][2] = { 0, }; // 0 = 얼리 어답터가 아님, 1 = 얼리 어답터임

void dfs(int current) // 1번 정점이 루트인거면, 1번 정점부터 어답터냐 아니냐를 판단해야하는듯?
{
	dp[current][1] = 1; // 어답터니까 1
	visited[current] = 1;
	for (auto& i : graph[current])
	{
		if (!visited[i])
		{
			dfs(i);
			dp[current][0] += dp[i][1]; // 자신(부모)가 얼리 어답터가 아니면 친구(자식)은 무조건 얼리 어답터여야함
			dp[current][1] += min(dp[i][0], dp[i][1]); // 자신(부모)가 얼리 어답터면 친구(자식)이 얼리 어답터든, 아니든 상관 x 이니 작은값 취하기
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	for (int i = 0; i < num-1; ++i) // 항상 1번 정점이 루트인건가??
	{
		int p = 0, c = 0;
		cin >> p >> c;
		graph[p].push_back(c);
		graph[c].push_back(p);
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
	return 0;
}