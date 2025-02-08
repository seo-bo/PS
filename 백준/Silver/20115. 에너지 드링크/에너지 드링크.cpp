#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<lb>v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	lb result = v[N - 1];
	for (int i = 0; i < N - 1; ++i)
	{
		result += v[i] / 2;
	}
	cout << fixed << setprecision(2) << result;
	return 0;
}
