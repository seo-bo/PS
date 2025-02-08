#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1)
	{
		int n = 0;
		cin >> n;
		if (!n)
		{
			break;
		}
		vector<int>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		vector<bool>visited(n);
		vector<int>t;
		function<void(int)> dfs = [&](int start) -> void
			{
				if (t.size() == 6)
				{
					for (auto& i : t)
					{
						cout << i << " ";
					}
					cout << "\n";
					return;
				}
				for (int i = start; i < n; ++i)
				{
					if (!visited[i])
					{
						visited[i] = true;
						t.push_back(v[i]);
						dfs(i + 1);
						t.pop_back();
						visited[i] = false;
					}
				}
			};
		dfs(0);
		cout << "\n";
	}
	return 0;
}