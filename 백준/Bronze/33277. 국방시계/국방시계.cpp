#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	int pivot = b * 1440 / a;
	if (a == 0)
	{
		cout << "00:00";
		return 0;
	}
	int aa = pivot / 60, bb = pivot % 60;
	cout << setw(2) << setfill('0') << aa << ":" << setw(2) << setfill('0') << bb;
	return 0;
}