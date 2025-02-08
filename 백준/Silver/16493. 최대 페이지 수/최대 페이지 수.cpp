#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int dp[200][200] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int day = 0, chapter = 0;
	cin >> day >> chapter;
	vector<pair<int, int>>v((chapter + 1), { 0,0 }); // 일수 , 페이지 수
	for (int i = 1; i <= chapter; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 1; i <= chapter; ++i) // 챕터
	{
		for (int j = 0; j <= day; ++j) // 날짜
		{
			if (j - v[i].first >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
			}
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}
	cout << dp[chapter][day];
	return 0;
}