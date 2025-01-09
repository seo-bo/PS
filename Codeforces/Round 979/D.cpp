#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tl;
typedef tuple<int, int, int>tp;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, q = 0;
		cin >> n >> q;
		vector<ll> v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		vector<ll> mintree(n * 4, 0), maxtree(n * 4, 0);
		function<void(int, int, int)> init = [&](int start, int end, int node)
			{
				if (start == end)
				{
					mintree[node] = v[start];
					maxtree[node] = v[start];
					return;
				}
				int mid = (start + end) / 2;
				init(start, mid, node * 2);
				init(mid + 1, end, node * 2 + 1);
				mintree[node] = min(mintree[node * 2], mintree[node * 2 + 1]);
				maxtree[node] = max(maxtree[node * 2], maxtree[node * 2 + 1]);
			};
		function<pll(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right) -> pll
			{
				if (right < start || left > end)
				{
					return make_pair(LLONG_MAX, LLONG_MIN);
				}
				if (left <= start && end <= right)
				{
					return make_pair(mintree[node], maxtree[node]);
				}
				int mid = (start + end) / 2;
				pll L = query(start, mid, node * 2, left, right);
				pll R = query(mid + 1, end, node * 2 + 1, left, right);
				return make_pair(min(L.first, R.first), max(L.second, R.second));
			};
		init(0, n - 1, 1);
		string str;
		cin >> str;
		set<pii>ss;
		for (int i = 0; i < n; i++)
		{
			ss.insert(make_pair(i, i));
		}
		auto find = [&](int p)
			{
				auto it = ss.upper_bound(make_pair(p, INT_MAX));
				if (it == ss.begin())
				{
					return ss.end();
				}
				--it;
				if (it->first <= p && p <= it->second)
				{
					return it;
				}
				return ss.end();
			};
		auto cal = [&](int L, int R) -> bool
			{
				pll res = query(0, n - 1, 1, L, R);
				return (res.first != (L + 1)) || (res.second != (R + 1));
			};
		for (int i = 0; i < n - 1; i++)
		{
			if (str[i] == 'R' || str[i + 1] == 'L')
			{
				auto it1 = find(i);
				auto it2 = find(i + 1);
				if (it1 != it2 && it1 != ss.end() && it2 != ss.end())
				{
					int L = min(it1->first, it2->first);
					int R = max(it1->second, it2->second);
					ss.erase(it1);
					ss.erase(it2);
					ss.insert(make_pair(L, R));
				}
			}
		}
		ll res = 0;
		for (auto it : ss)
		{
			if (cal(it.first, it.second))
			{
				res++;
			}
		}
		while (q--)
		{
			int idx;
			cin >> idx;
			idx--;
			vector<pii>temp;
			if (idx > 0)
			{
				temp.push_back(make_pair(idx - 1, idx));
			}
			if (idx < n - 1)
			{
				temp.push_back(make_pair(idx, idx + 1));
			}
			int len = temp.size();
			vector<bool> pre(len);
			for (int i = 0; i < len; i++)
			{
				auto [a, b] = temp[i];
				pre[i] = (str[a] == 'R' || str[b] == 'L');
			}
			str[idx] = (str[idx] == 'L') ? 'R' : 'L';
			vector<bool> now(len);
			for (int i = 0; i < len; i++)
			{
				auto [a, b] = temp[i];
				now[i] = (str[a] == 'R' || str[b] == 'L');
			}
			for (int i = 0; i < len; i++)
			{
				auto [a, b] = temp[i];
				if (pre[i] && !now[i])
				{
					auto it = find(a);
					if (it != ss.end() && it->first <= a && it->second >= b)
					{
						if (cal(it->first, it->second))
						{
							res--;
						}
						int L = it->first;
						int R = it->second;
						ss.erase(it);
						ss.insert(make_pair(L, a));
						ss.insert(make_pair(b, R));
						if (cal(L, a))
						{
							res++;
						}
						if (cal(b, R))
						{
							res++;
						}
					}
				}
				else if (!pre[i] && now[i])
				{
					auto it1 = find(a);
					auto it2 = find(b);
					if (it1 != ss.end() && it2 != ss.end() && it1 != it2)
					{
						if (cal(it1->first, it1->second))
						{
							res--;
						}
						if (cal(it2->first, it2->second))
						{
							res--;
						}
						int L = min(it1->first, it2->first);
						int R = max(it1->second, it2->second);
						ss.erase(it1);
						ss.erase(it2);
						ss.insert(make_pair(L, R));
						if (cal(L, R))
						{
							res++;
						}
					}
				}
			}
			if (res == 0)
			{
				cout << yes << '\n';
			}
			else
			{
				cout << no << '\n';
			}
		}
	}
	return 0;
}
