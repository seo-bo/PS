#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) // 기여를 한 놈은 더이상 대회에 참가 불가하다. 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0;
	cin >> N >> M;
	vector<int>v(N, 0);
	vector<pair<int, int>>od(M, { 0,0 });
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](const int& a, const int& b)
		{
			return a > b;
		});
	ll sum = 0, temp = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> od[i].first >> od[i].second;
		while (sum < od[i].second)
		{
			if (temp >= N) // 끝까지 갔는데, 못찾은거면 만들수 없는거기 때문에
			{
				cout << -1;
				return 0;
			}
			sum += v[temp] + od[i].first;
			temp++;
		}
		if (i == M - 1) // 미친 '막조건' 있는날까지 만들어진 문제잖아
		{
			while (temp < N)
			{
				sum += v[temp] + od[i].first;
				temp++;
			}
		}
	}
	
	cout << sum;
	return 0;
}