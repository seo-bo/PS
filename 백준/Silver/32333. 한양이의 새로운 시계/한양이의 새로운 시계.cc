#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, cnt = 0;
	cin >> n;
	vector<pii>v;
	vector<string>ani = { "rat","cow","tiger","rabbit","dragon","snake","horse","sheep","monkey","chicken","dog","pig","lion","giraffe","cat" };
	vector<int>time;
	int tdx = 0;
	for (int i = 0; i < 1440; i += 96, tdx++)
	{
		time.push_back(i);
	}
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		int start = a * 60 + b;
		int end = start + c;
		if (end >= 1440)
		{
			cnt++;
			continue;
		}
		v.push_back(make_pair(start, c));
	}
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first < b.first;
		});
	int start = 0;
	bool check = false;
	auto print = [&](int tt)
		{
			int h = tt / 60, m = tt % 60;
			auto f = [&](int a)
				{
					if (a < 10)
					{
						cout << 0;
					}
				};
			f(h);
			cout << h << ":";
			f(m);
			cout << m;
		};
	for (auto& [a, b] : v)
	{
		if (check)
		{
			cnt++;
			continue;
		}
		start = max(start, a);
		int end = start + b;
		if (end >= 1440)
		{
			cnt++;
			check = true;
			continue;
		}
		auto it = lower_bound(time.begin(), time.end(), start);
		auto jt = upper_bound(time.begin(), time.end(), end) - time.begin();
		if (it != time.begin() && (it == time.end() || *it != start))
		{
			--it;
		}
		for (int i = (it - time.begin()); i < jt; ++i)
		{
			cout << ani[i] << ' ';
		}
		cout << '\n';
		print(start);
		cout << ' ';
		print(end);
		cout << '\n';
		start = end;
	}
	if (cnt)
	{
		cout << cnt;
	}
	return 0;
}