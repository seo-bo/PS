#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int N = 0, K = 0, L = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	cin >> N >> K >> L;
	while (K != L)
	{
		K -= K / 2;
		L -= L / 2;
		cnt++;
	}
	cout << cnt;
	return 0;
}