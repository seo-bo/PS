#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	int aa = a * 60 + b;
	int bb = c * 60 + d;
	if (bb < aa)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}
