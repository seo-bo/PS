#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct fac
{
	int a, b, c;
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>parent(n + 1, 0);
	vector<fac>v;
	priority_queue<int, vector<int>, greater<int>>pq;
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int num) -> int
		{
			if (parent[num] == num)
			{
				return num;
			}
			return parent[num] = find(parent[num]);
		};
	auto Union = [&](int num1, int num2) -> void
		{
			int r1 = find(num1);
			int r2 = find(num2);
			if (r1 != r2)
			{
				parent[r2] = r1;
			}
		};
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	int start = 0, end = 0;
	cin >> start >> end;
	sort(v.begin(), v.end(), [&](const fac& a, const fac& b)
		{
			return a.c > b.c;
		});
	for (auto& i : v)
	{
		if (find(i.a) != find(i.b))
		{
			Union(i.a, i.b);
			pq.push(i.c);
		}
		if (find(start) == find(end))
		{
			cout << pq.top();
			return 0;
		}
	}
	return 0;
}