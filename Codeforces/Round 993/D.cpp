#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, idx = 1;
		cin >> n;
		vector<bool>visited(n + 2, false);
		vector<int>a(n + 2), b(n + 2);
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (!visited[a[i]])
			{
				visited[a[i]] = true;
				b[i] = a[i];
			}
			else
			{
				while (visited[idx])
				{
					idx = (idx + 1) % (n + 1);
					if (idx == 0)
					{
						idx = 1;
					}
				}
				visited[idx] = true;
				b[i] = idx;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			cout << b[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
