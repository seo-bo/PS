#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int k = 0, n = 0, cnt = 0, ver = 0;
	cin >> k >> n;
	int N = 2 * (k + 1);
	vector<vector<int>>graph(N);
	vector<int>num(N, 0), low(N, 0), id(N, -1), S;
	vector<bool>in(N, false);
	auto add = [&](int a, int b)
		{
			bool aa = a > 0, bb = b > 0;
			a = abs(a), b = abs(b);
			int notA = 2 * a + !aa;
			int A = 2 * a + aa;
			int notB = 2 * b + !bb;
			int B = 2 * b + bb;
			graph[notA].push_back(B);
			graph[notB].push_back(A);
		};
	function<void(int)> scc = [&](int node)
		{
			low[node] = num[node] = ++cnt;
			S.push_back(node);
			in[node] = true;
			for (auto& i : graph[node])
			{
				if (!num[i])
				{
					scc(i);
					low[node] = min(low[node], low[i]);
				}
				else if (in[i])
				{
					low[node] = min(low[node], num[i]);
				}
			}
			if (num[node] == low[node])
			{
				while (1)
				{
					int a = S.back();
					S.pop_back();
					in[a] = false;
					id[a] = ver;
					if (node == a)
					{
						break;
					}
				}
				ver++;
			}
		};
	for (int i = 0; i < n; ++i)
	{
		int n1 = 0, n2 = 0, n3 = 0;
		char c1, c2, c3;
		cin >> n1 >> c1 >> n2 >> c2 >> n3 >> c3;
		n1 = (c1 == 'B') ? n1 : -n1;
		n2 = (c2 == 'B') ? n2 : -n2;
		n3 = (c3 == 'B') ? n3 : -n3;
		add(n1, n2);
		add(n2, n3);
		add(n1, n3);
	}
	for (int i = 2; i <= 2 * k + 1; ++i)
	{
		if (!num[i])
		{
			scc(i);
		}
	}
	for (int i = 1; i <= k; ++i)
	{
		if (id[2 * i] == id[2 * i + 1])
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= k; ++i)
	{
		if (id[2 * i] > id[2 * i + 1])
		{
			cout << 'B';
		}
		else
		{
			cout << 'R';
		}
	}
	return 0;
}