#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int c = 0, v = 0;
		cin >> c >> v;
		vector<vector<int>>a(v); // 선호도 정보
		vector<pii>voted(c + 1); // 1차 투표 정보
		vector<pii>score(c + 1); // 2차 투표 정보
		vector<bool>visited(c + 1, false); // 1등 2등 저장
		for (int i = 0; i < v; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				voted[j + 1].second = j + 1;
				score[j + 1].second = j + 1;
				int temp = 0;
				cin >> temp;
				a[i].push_back(temp);
				if (!j)
				{
					voted[temp].first++;
				}
			}
		}
		sort(voted.begin(), voted.end(), [&](const pii& a, const pii& b)
			{
				return a.first > b.first;
			});
		int pivot = voted[0].first;
		if (pivot >= (v / 2) + 1)
		{
			cout << voted[0].second << " " << 1 << '\n';
			continue;
		}
		visited[voted[0].second] = true;
		visited[voted[1].second] = true;
		for (auto& i : a)
		{
			for (auto& j : i)
			{
				if (!visited[j])
				{
					continue;
				}
				score[j].first++;
				break;
			}
		}
		sort(score.begin(), score.end(), [&](const pii& a, const pii& b)
			{
				return a.first > b.first;
			});
		cout << score[0].second << " " << 2 << '\n';
	}
	return 0;
}