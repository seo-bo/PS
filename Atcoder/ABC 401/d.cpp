#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, cnt = 0;
	cin >> n >> k;
	vector<bool>visited(n, false);
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '?')
		{
			if (i - 1 >= 0 && str[i - 1] == 'o')
			{
				str[i] = '.';
			}
			else if (i + 1 < n && str[i + 1] == 'o')
			{
				str[i] = '.';
			}
			else
			{
				visited[i] = true;
			}
		}
		else if (str[i] == 'o')
		{
			cnt++;
		}
	}
	vector<pii>v;
	for (int i = 0; i < n;)
	{
		if (visited[i])
		{
			int idx = i;
			while (idx < n && visited[idx])
			{
				idx++;
			}
			v.push_back(make_pair(i, idx - i));
			i = idx;
			continue;
		}
		i++;
	}
	k -= cnt;
	int siz = v.size(), ok = 0;
	vector<int>A, B(siz + 1, -1);
	for (auto& [a, b] : v)
	{
		A.push_back((b + 1) / 2);
		ok += A.back();
	}
	for (int i = 0; i < siz; ++i)
	{
		int a = max(0, k - (ok - A[i]));
		if (a == min(A[i], k))
		{
			B[i] = a;
		}
	}
	for (int i = 0; i < siz; ++i)
	{
		auto [a, b] = v[i];
		if (B[i] == -1)
		{
			continue;
		}
		if (!B[i])
		{
			for (int j = 0; j < b; ++j)
			{
				str[a + j] = '.';
			}
		}
		else if (b == 1 && B[i] == 1)
		{
			str[a] = 'o';
		}
		else if (b % 2 && (B[i] == (b + 1) / 2))
		{
			for (int j = 0; j < b; ++j)
			{
				str[a + j] = ((j % 2) ? '.' : 'o');
			}
		}
		else
		{
			for (int j = 0; j < b; ++j)
			{
				str[a + j] = '?';
			}
		}
	}
	cout << str;
	return 0;
}
