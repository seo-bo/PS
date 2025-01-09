#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<deque<int>>temp;
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto rot = [&]
		{
			int a = n, b = m, cnt = 0, pivot = min(a, b) / 2;
			for (int _ = 0; _ < pivot; ++_)
			{
				deque<int>dq;
				for (int i = cnt; i < a - 1; ++i)
				{
					dq.push_back(v[i][cnt]);
				}
				for (int i = cnt; i < b - 1; ++i)
				{
					dq.push_back(v[a - 1][i]);
				}
				for (int i = a - 1; i > cnt; --i)
				{
					dq.push_back(v[i][b - 1]);
				}
				for (int i = b - 1; i > cnt; --i)
				{
					dq.push_back(v[cnt][i]);
				}
				temp.push_back(dq);
				cnt++;
				a--, b--;
			}
		};
	auto pus = [&]
		{
			int a = n, b = m, cnt = 0, pivot = min(a, b) / 2;
			for (int _ = 0; _ < pivot; ++_)
			{
				for (int i = cnt; i < a - 1; ++i)
				{
					v[i][cnt] = temp[_].front();
					temp[_].pop_front();
				}
				for (int i = cnt; i < b - 1; ++i)
				{
					v[a - 1][i] = temp[_].front();
					temp[_].pop_front();
				}
				for (int i = a - 1; i > cnt; --i)
				{
					v[i][b - 1] = temp[_].front();
					temp[_].pop_front();
				}
				for (int i = b - 1; i > cnt; --i)
				{
					v[cnt][i] = temp[_].front();
					temp[_].pop_front();
				}
				cnt++;
				a--, b--;
			}
		};
	rot();
	for (int i = 0; i < k; ++i)
	{
		for (auto& a : temp)
		{
			a.push_front(a.back());
			a.pop_back();
		}
	}
	pus();
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}