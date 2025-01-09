#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Ahri = (1 << 10) - 1;
	int S = 0, M = 0;
	cin >> S >> M;
	if (S <= Ahri)
	{
		cout << "No thanks";
		return 0;
	}
	if (((S - Ahri) & M) == (S - Ahri))
	{
		cout << "Thanks";
	}
	else
	{
		cout << "Impossible";
	}
	return 0;
}