#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)  
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;
	vector<string>v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		sort(v[i].begin(), v[i].end());
	}
	sort(v.begin(), v.end());
	string result = "";
	int cnt = 0;
	for (auto& i : v)
	{
		if (cnt == K)
		{
			break;
		}
		result += i;
		cnt++;
	}
	sort(result.begin(), result.end());
	cout << result;
	return 0;
}