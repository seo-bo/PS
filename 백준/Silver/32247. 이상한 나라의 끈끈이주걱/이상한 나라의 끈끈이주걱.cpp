#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 문제를 잘못읽었네... 올라가는건 무제한
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, x = 0, y = 0;
	cin >> n >> m;
	if (!m)
	{
		cout << "stay";
		return 0;
	}
	vector<ti>v;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		a ? (c--) : (c++);
		v.push_back(make_tuple(a, b, c));
	}
	sort(v.begin(), v.end(), [&](const ti& a, const ti& b)
		{
			return get<1>(a) < get<1>(b);
		});
	for (int i = 0; i < m; ++i)
	{
		auto [f, nx, ny] = v[i];
		y = y - (nx - x); // 내려가기 시도
		x = nx;
		if (!f)
		{
			y = max(y, ny);
		}
		else
		{
			if (ny < y)
			{
				cout << "adios"; // ???????? ????????? ?????????
				return 0;
			}
		}
	}
	if (y > (n - x))
	{
		cout << "adios";
	}
	else
	{
		cout << "stay";
	}
	return 0;
}