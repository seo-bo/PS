#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	double v = 0, m = 0, sx = 0, sy = 0, tx = 0, ty = 0;
	cin >> v >> m >> sx >> sy >> tx >> ty;
	m *= 60 * v;
	set<pdd>visited;
	vector<pdd>pos;
	string str;
	cin.ignore();
	while (getline(cin, str))
	{
		if (str.empty())
		{
			continue;
		}
		stringstream ss(str);
		string temp;
		vector<double>tt;
		while (ss >> temp)
		{
			tt.push_back(stod(temp));
		}
		pos.push_back(make_pair(tt[0], tt[1]));
	}
	auto dis = [&](pdd a, pdd b)
		{
			double temp = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
			return (temp < m * m);
		};
	queue<tuple<int, double, double>>q;
	q.push(make_tuple(0, sx, sy));
	visited.insert(make_pair(sx, sy));
	while (!q.empty())
	{
		auto [a, b, c] = q.front();
		q.pop();
		if (dis(make_pair(b, c), make_pair(tx, ty)))
		{
			cout << "Yes, visiting " << a << " other holes.";
			exit(0);
		}
		for (auto& i : pos)
		{
			if (dis(make_pair(b, c), i) && visited.find(i) == visited.end())
			{
				visited.insert(i);
				q.push(make_tuple(a + 1, i.first, i.second));
			}
		}
	}
	cout << "No.";
	return 0;
}