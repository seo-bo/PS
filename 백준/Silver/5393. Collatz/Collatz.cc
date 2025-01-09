#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while(T--)
	{
		lb N = 0;
		cin >> N;
		ll result = (ll)ceil(N/2) + (ll)ceil(N/2);
		result -= (ll)ceil(floor((N-1)/3)/2);
		cout << result << '\n';
	}
	return 0;
}
