#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);;
	int n = 0;
	cin >> n;
	vector<vector<int>>ball(n, vector<int>(9, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> ball[i][j];
		}
	}
	vector<int>ss = { 0,1,3,7 };
	vector<int>temp;
	for (int i = 1; i < 9; ++i)
	{
		temp.push_back(i);
	}
	int ans = 0;
	do
	{
		int score = 0, start = 0;
		for (int i = 0; i < n; ++i)
		{
			int base = 0, out = 0;
			for (int j = start; j < 9; j = (j + 1) % 9)
			{
				int batter = 0;
				if (j < 3)
				{
					batter = temp[j];
				}
				else if (j > 3)
				{
					batter = temp[j - 1];
				}
				int pivot = ball[i][batter];
				if (!pivot)
				{
					out++;
				}
				else if (pivot == 4)
				{
					score += __builtin_popcount(base) + 1;
					base = 0;
				}
				else
				{
					int _ = base & ss[pivot];
					score += __builtin_popcount(_);
					base >>= pivot;
					base |= (1 << (3 - pivot));
				}
				if (out == 3)
				{
					start = (j + 1) % 9;
					break;
				}
			}
		}
		ans = max(ans, score);
	} while (next_permutation(temp.begin(), temp.end())); // 40320
	cout << ans;
	return 0;
}