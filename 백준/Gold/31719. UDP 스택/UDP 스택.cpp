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
		int n = 0;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		vector<int>sorted = v;
		sort(sorted.begin(), sorted.end());
		auto sv = [&]
			{
				deque<int>a, b;
				int idx = 0;
				for (int i = 0; i < n; ++i)
				{
					if (sorted[idx] == v[i])
					{
						idx++;
						continue;
					}
					if (!a.empty() && a.front() == sorted[idx])
					{
						while (!a.empty() && idx < n)
						{
							if (a.front() == sorted[idx])
							{
								a.pop_front();
								idx++;
							}
							else
							{
								return false;
							}
						}
					}
					if (!b.empty() && b.front() == sorted[idx])
					{
						while (!b.empty() && idx < n)
						{
							if (b.front() == sorted[idx])
							{
								b.pop_front();
								idx++;
							}
							else
							{
								return false;
							}
						}
					}
					if (a.empty() && b.empty())
					{
						a.push_back(v[i]);
					}
					else if (!a.empty() && b.empty())
					{
						auto it = upper_bound(sorted.begin(), sorted.end(), a.back());
						if (it == sorted.end() || *it != v[i])
						{
							b.push_back(v[i]);
						}
						else if (*it == v[i])
						{
							a.push_back(v[i]);
						}
					}
					else if (a.empty() && !b.empty())
					{
						auto it = upper_bound(sorted.begin(), sorted.end(), b.back());
						if (it == sorted.end() || *it != v[i])
						{
							a.push_back(v[i]);
						}
						else if (*it == v[i])
						{
							b.push_back(v[i]);
						}
					}
					else
					{
						auto it = upper_bound(sorted.begin(), sorted.end(), a.back());
						auto jt = upper_bound(sorted.begin(), sorted.end(), b.back());
						if (it == sorted.end())
						{
							if (*jt != v[i])
							{
								return false;
							}
							else
							{
								b.push_back(v[i]);
							}
						}
						else if (jt == sorted.end())
						{
							if (*it != v[i])
							{
								return false;
							}
							else
							{
								a.push_back(v[i]);
							}
						}
						else
						{
							if (*it == v[i])
							{
								a.push_back(v[i]);
							}
							else if (*jt == v[i])
							{
								b.push_back(v[i]);
							}
							else
							{
								return false;
							}
						}
					}
				}
				if (!a.empty() && b.empty())
				{
					while (!a.empty() && idx < n)
					{
						if (a.front() == sorted[idx])
						{
							a.pop_front();
							idx++;
						}
						else
						{
							return false;
						}
					}
				}
				else if (a.empty() && !b.empty())
				{
					while (!b.empty() && idx < n)
					{
						if (b.front() == sorted[idx])
						{
							b.pop_front();
							idx++;
						}
						else
						{
							return false;
						}
					}
				}
				else if (!a.empty() && !b.empty())
				{
					if (a.front() == sorted[idx])
					{
						while (!a.empty() && idx < n)
						{
							if (a.front() == sorted[idx])
							{
								a.pop_front();
								idx++;
							}
							else
							{
								return false;
							}
						}
						while (!b.empty() && idx < n)
						{
							if (b.front() == sorted[idx])
							{
								b.pop_front();
								idx++;
							}
							else
							{
								return false;
							}
						}
					}
					else if (b.front() == sorted[idx])
					{
						while (!b.empty() && idx < n)
						{
							if (b.front() == sorted[idx])
							{
								b.pop_front();
								idx++;
							}
							else
							{
								return false;
							}
						}
						while (!a.empty() && idx < n)
						{
							if (a.front() == sorted[idx])
							{
								a.pop_front();
								idx++;
							}
							else
							{
								return false;
							}
						}
					}
					else
					{
						return false;
					}
				}
				return true;
			};
		cout << ((sv()) ? "YES" : "NO") << '\n';
	}
	return 0;
}