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
	int n = 0, d = 0, m = 0, total = 0, delc = 0;
	string str;
	cin >> n >> str >> d >> m;
	unordered_map<char, int>mm;
	for (auto& i : str)
	{
		if (i == 'H' || i == 'Y' || i == 'U')
		{
			mm[i]++;
			total += min(d + m, delc * d); // 아니 그냥 H, Y, U는 지우면 안되는건가?
			delc = 0;
		}
		else
		{
			delc++;
		}
	}
	if (delc)
	{
		total += min(d + m, delc * d);
	}
	int ans = min(mm['H'], min(mm['Y'], mm['U']));
	if (total)
	{
		cout << total << '\n';
	}
	else
	{
		cout << "Nalmeok" << '\n';
	}
	if (ans)
	{
		cout << ans;
	}
	else
	{
		cout << "I love HanYang University";
	}
	return 0;
}