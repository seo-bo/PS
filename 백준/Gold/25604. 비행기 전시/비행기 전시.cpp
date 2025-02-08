#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>tp;
typedef pair<int, int> pii;

int main(void) // 항상 0번 시작
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, T = 0, time = 0;
	cin >> n >> m >> T;
	queue<tp>A, B;
	vector<pii>ans(n, make_pair(-1, -1));
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (!a)
		{
			A.push(make_tuple(c, b, i));
		}
		else
		{
			B.push(make_tuple(c, b, i));
		}
	}
	int turn = 0;
	while (!A.empty() || !B.empty())
	{
		int lim = m;
		if (!turn)
		{
			if (A.empty())
			{
				time += T;
				turn = (turn + 1) % 2;
				continue;
			}
			if (!A.empty() && !B.empty())
			{
				if (time < get<0>(A.front()) && get<0>(B.front()) < get<0>(A.front()))
				{
					time = max(get<0>(B.front()), time) + T;
					turn = (turn + 1) % 2;
					continue;
				}
			}
			time = max(time, get<0>(A.front()));
			int cost = time + T;
			while (!A.empty() && lim)
			{
				auto& [a, b, c] = A.front();
				if (a > time)
				{
					break;
				}
				if (ans[c].first == -1)
				{
					ans[c].first = time;
				}
				if (lim >= b)
				{
					ans[c].second = cost;
					lim -= b;
					A.pop();
				}
				else
				{
					b -= lim;
					lim = 0;
				}
			}
			time = cost;
		}
		else
		{
			if (B.empty())
			{
				time += T;
				turn = (turn + 1) % 2;
				continue;
			}
			if (!A.empty() && !B.empty())
			{
				if (time < get<0>(B.front()) && get<0>(B.front()) > get<0>(A.front()))
				{
					time = max(get<0>(A.front()), time) + T;
					turn = (turn + 1) % 2;
					continue;
				}
			}
			time = max(time, get<0>(B.front()));
			int cost = time + T;
			while (!B.empty() && lim)
			{
				auto& [a, b, c] = B.front();
				if (a > time)
				{
					break;
				}
				if (ans[c].first == -1)
				{
					ans[c].first = time;
				}
				if (lim >= b)
				{
					ans[c].second = cost;
					lim -= b;
					B.pop();
				}
				else
				{
					b -= lim;
					lim = 0;
				}
			}
			time = cost;
		}
		turn = (turn + 1) % 2;
	}
	for (auto& [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}