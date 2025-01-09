#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	deque<int>dq;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		dq.push_back(temp);
	}
	for (int i = 0; i < k; ++i)
	{
		dq.push_front(dq.back());
		dq.pop_back();
	}
	for (auto& i : dq)
	{
		cout << i << ' ';
	}
	return 0;
}
