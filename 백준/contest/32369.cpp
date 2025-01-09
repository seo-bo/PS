#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 1 - 칭찬, 2 - 비난
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<int>onion(2, 1);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		onion[0] += a;
		onion[1] += b;
		if (onion[1] > onion[0])
		{
			swap(onion[0], onion[1]);
		}
		else if (onion[0] == onion[1])
		{
			onion[1]--;
		}
	}
	for (auto& i : onion)
	{
		cout << i << ' ';
	}
	return 0;
}
