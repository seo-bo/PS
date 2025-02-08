#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ull pivot = sqrt(1e15);
	vector<bool>vs(pivot + 3, true);
	vs[0] = vs[1] = false;
	vector<ull>prime;
	for (ull i = 2; i <= pivot; ++i)
	{
		if (vs[i])
		{
			prime.push_back(i);
			for (ull j = i * i; j <= pivot; j += i)
			{
				vs[j] = false;
			}
		}
	}
	ull ans = 0, a = 0, b = 0;
	cin >> a >> b;
	for (auto& i : prime)
	{
		ull mul = i * i;
		while (mul <= b)
		{
			if (mul >= a)
			{
				ans++;
			}
			if (mul > b / i)
			{
				break;
			}
			mul *= i;
		}
	}
	cout << ans;
	return 0;
}