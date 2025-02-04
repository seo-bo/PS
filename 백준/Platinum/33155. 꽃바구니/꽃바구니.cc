#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>A(n), B(m), v(n);
	vector<vector<int>>C(n, vector<int>(n, 0));
	vector<pii>base(1 << n);
	vector<int>p3(n + 1, 1);
	for (int i = 1; i <= n; ++i)
	{
		p3[i] = p3[i - 1] * 3;
	}
	int per = p3[n];
	vector<tp>ch(per);
	for (auto& i : A)
	{
		cin >> i;
	}
	for (auto& i : B)
	{
		cin >> i;
	}
	for (auto& i : v)
	{
		cin >> i;
	}
	for (auto& i : C)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < (1 << n); ++i)
	{
		int a = 0, b = 0, c = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				b += v[j];
				c += A[j];
				for (int k = j; k < n; ++k)
				{
					if (i & (1 << k))
					{
						a += C[j][k];
					}
				}
			}
		}
		if (b > k)
		{
			continue;
		}
		base[i] = make_pair(a, c); // 아름다움, 크기
	}
	int n1 = n / 2;
	int n2 = n - n1;
	int per1 = p3[n1], per2 = p3[n2];
	vector<tp> ch1(per1), ch2(per2);
	function<void(int, int, int, int, int)> rec1 = [&](int pos, int a, int b, int c, int idx)
		{
			if (pos == n1)
			{
				ch1[idx] = make_tuple(a, b, c);
				return;
			}
			rec1(pos + 1, a, b, c, 3 * idx);
			rec1(pos + 1, a | (1 << pos), b + 2 * p3[pos], c, 3 * idx + 1);
			rec1(pos + 1, a, b + 2 * p3[pos], c + 2 * p3[pos], 3 * idx + 2);
		};
	function<void(int, int, int, int, int)> rec2 = [&](int pos, int a, int b, int c, int idx)
		{
			if (pos == n2)
			{
				ch2[idx] = make_tuple(a, b, c);
				return;
			}
			rec2(pos + 1, a | (1 << (pos + n1)), b + 2 * p3[pos + n1], c, 3 * idx + 1);
			rec2(pos + 1, a, b, c, 3 * idx);
			rec2(pos + 1, a, b + 2 * p3[pos + n1], c + 2 * p3[pos + n1], 3 * idx + 2);
		};
	rec1(0, 0, 0, 0, 0);
	rec2(0, 0, 0, 0, 0);
	for (int i = 0; i < per1; i++)
	{
		auto& [a1, b1, c1] = ch1[i];
		for (int j = 0; j < per2; j++)
		{
			auto& [a2, b2, c2] = ch2[j];
			int idx = i * per2 + j;
			ch[idx] = make_tuple(a1 | a2, b1 + b2, c1 + c2);
		}
	}
	vector<int>dp(per, 0);
	sort(B.rbegin(), B.rend());
	for (int i = 0; i < min(n, m); ++i)
	{
		vector<int>temp(per, 0);
		for (int j = 0; j < per; ++j)
		{
			auto& [a, b, c] = ch[j]; // 2진수, 3진수 or연산, prev
			if (base[a].second > B[i])
			{
				continue;
			}
			temp[b] = max(temp[b], dp[c] + base[a].first);
		}
		dp = move(temp);
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}