#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>v = { 6,2,5,5,4,5,6,3,7,6 }; // 0 ~ 9 
	//0 1 2 3 4 5 6 7 8 9
	vector<string>maxi(101);
	vector<string>mini(101, string(101, '9'));
	mini[2] = "1", mini[3] = "7", mini[4] = "4", mini[5] = "2", mini[6] = "6", mini[7] = "8";
	maxi[2] = "1", maxi[3] = "7", maxi[4] = "11", maxi[5] = "71", maxi[6] = "111", maxi[7] = "711";
	for (int i = 8; i <= 100; ++i) // 몇개쓸건지?
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (v[j] > i)
			{
				continue;
			}
			string mini_temp = mini[i - v[j]] + to_string(j);
			string maxi_temp = maxi[i - v[j]] + to_string(j);
			if (mini[i].length() > mini_temp.length())
			{
				mini[i] = mini_temp;
			}
			else if (mini[i].length() == mini_temp.length())
			{
				mini[i] = min(mini[i], mini_temp);
			}
			if (maxi[i].length() < maxi_temp.length())
			{
				maxi[i] = maxi_temp;
			}
			else if (maxi[i].length() == maxi_temp.length())
			{
				maxi[i] = max(maxi[i], maxi_temp);
			}
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		cout << mini[n] << ' ' << maxi[n] << '\n';
	}
	return 0;
}