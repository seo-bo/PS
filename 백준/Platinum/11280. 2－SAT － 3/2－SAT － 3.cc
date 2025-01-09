#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // scc 꿀쟴
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, cnt = 0, ver = 0;
	cin >> n >> m;
	int N = n + 1;
	vector<vector<int>>g(2 * N);
	vector<int>num(2 * N, 0), low(2 * N, 0), id(2 * N, -1), S;
	vector<bool>in(2 * N, false);
	auto add = [&](int a, bool aa, int b, bool bb)
		{
			int notA = a * 2 + !aa;
			int A = a * 2 + aa;
			int notB = b * 2 + !bb;
			int B = b * 2 + bb;
			g[notA].push_back(B);
			g[notB].push_back(A);
		};
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		add(abs(a), (a > 0), abs(b), (b > 0));
	}
	function<void(int)> scc = [&](int node)
		{
			num[node] = low[node] = ++cnt;
			S.push_back(node);
			in[node] = true;
			for (auto& i : g[node])
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
					id[a] = ver;
					in[a] = false;
					if (a == node)
					{
						break;
					}
				}
				ver++;
			}
		};
	for (int i = 1; i <= 2 * n; ++i)
	{
		if (!num[i])
		{
			scc(i);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (id[2 * i] == id[2 * i + 1])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}