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

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	string str, temp;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'A')
		{
			for (int j = i + 2; j < n; ++j)
			{
				if (str[j] == 'A')
				{
					int cnt1 = 0, cnt2 = 0;
					for (int k = i + 1; k < j; ++k)
					{
						if (str[k] == 'A')
						{
							cnt1++;
						}
						else if (str[k] == 'N')
						{
							cnt2++;
						}
					}
					if (cnt1 == 0 && cnt2 == 1)
					{
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}