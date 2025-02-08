#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	string str;
	while (getline(cin, str))
	{
		string temp;
		stringstream ss(str);
		vector<int>v;
		while (ss >> temp)
		{
			v.push_back(stoi(temp));
		}
		int n = v[0], m = v[1], cnt = 0, ver = 0;
		int N = 2 * (n + 1);
		vector<vector<int>>g(N);
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
				g[notA].push_back(B);
				g[notB].push_back(A);
			};
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
						in[a] = false;
						id[a] = ver;
						if (a == node)
						{
							break;
						}
					}
					ver++;
				}
			};
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			add(a, b);
		}
		add(1, 1);
		for (int i = 2; i <= 2 * n + 1; ++i)
		{
			if (!num[i])
			{
				scc(i);
			}
		}
		bool flag = true;
		for (int i = 1; i <= n && flag; ++i)
		{
			if (id[2 * i] == id[2 * i + 1])
			{
				flag = false;
			}
		}
		if (flag)
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
		cin.ignore();
	}
	return 0;
}