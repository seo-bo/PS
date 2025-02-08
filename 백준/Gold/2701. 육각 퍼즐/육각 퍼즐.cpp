#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<string, string> ps;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	string ans = "ABCDEFo";
	auto solve = [&] // 7번째에!
		{
			string str;
			cin >> str;
			str += 'o';
			unordered_set<string>visited;
			visited.insert(str);
			queue<ps>q;
			q.push(make_pair(str, ""));
			while (!q.empty())
			{
				auto [p, res] = q.front();
				q.pop();
				if (p == ans)
				{
					cout << res.size() << ' ' << res << '\n';
					return true;
				}
				if (p[6] == 'o') // 중앙에 들어간 놈이 아무것도 없을때
				{
					for (auto& i : { 1,4 })
					{
						string tp = p, tan = res;
						tan += tp[i];
						swap(tp[i], tp[6]);
						if (visited.find(tp) != visited.end())
						{
							continue;
						}
						visited.insert(tp);
						q.push(make_pair(tp, tan));
					}
				}
				else
				{
					for (int i = 0; i < 6; ++i)
					{
						if (p[i] != 'o')
						{
							continue;
						}
						for (auto& j : { (i + 5) % 6, (i + 1) % 6 })
						{
							string tp = p, tan = res;
							tan += tp[j];
							swap(tp[i], tp[j]);
							if (visited.find(tp) != visited.end())
							{
								continue;
							}
							visited.insert(tp);
							q.push(make_pair(tp, tan));
						}
						if (i == 1 || i == 4)
						{
							string tp = p, tan = res;
							tan += tp[6];
							swap(tp[i], tp[6]);
							if (visited.find(tp) != visited.end())
							{
								continue;
							}
							visited.insert(tp);
							q.push(make_pair(tp, tan));
						}
					}
				}
			}
			cout << -1 << '\n';
			return false;
		};
	while (T--)
	{
		solve();
	}
	return 0;
}