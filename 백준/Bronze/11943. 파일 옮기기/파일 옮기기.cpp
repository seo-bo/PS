#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	cout << min(a + d, b + c);
	return 0;
}