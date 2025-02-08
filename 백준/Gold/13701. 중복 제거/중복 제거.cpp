#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<33554433>visited;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	while (cin >> n)
	{
		if (visited[n])
		{
			continue;
		}
		visited[n] = 1;
		cout << n << ' ';
	}
	return 0;
}