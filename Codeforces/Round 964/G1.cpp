#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";
#define MOD 1000000007

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--) // endl로만은 불안한가?
	{
		int left = 2, right = 1000;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			cout << "? " << mid << " " << mid << endl;
			cout.flush();
			int res = 0;
			cin >> res;
			if (res == -1)
			{
				exit(0);
			}
			if (res == (mid + 1) * (mid + 1))
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << "! " << left << endl;
		cout.flush();
	}
	return 0;
}
