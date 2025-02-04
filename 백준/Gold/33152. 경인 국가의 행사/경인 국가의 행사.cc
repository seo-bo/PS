#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
/*
  원소 개수가 짝수일때 비기는건 y의 카운트를 감소시키지만 (4일때 1,3인데, 1,2로)
  원소 개수가 홀수일때 비기는건 x의 카운트를 감소시킴(7일때 3,4인데 -> 2,4, 5일때 -> 1, 3)
  또한 원소가 짝수일때만 비길 수 있으니까
  딱 한 도시만 골라서 비기게 만든다면? 근데 그거는 과반수 넘었을때 하면 되지 않을까?
  어쩌피 Y가 못이기는 상황은 없잖아?
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<pll>v;
		vector<ll>a1(n, 0), b1(n, 0);
		vector<ll>a2(n, 0), b2(n, 0);
		ll suma1 = 0, sumb1 = 0;
		ll suma2 = 0, sumb2 = 0;
		bool check = true;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			v.push_back(make_pair(temp, i));
			if (n % 2 == 0 && temp % 2 == 0 && check)
			{
				ll pp = temp / 2;
				a1[i] = b1[i] = pp;
				suma1 += pp;
				sumb1 += pp;
				check = false;
			}
		}
		ll pivot = (n - 1) / 2;
		sort(v.rbegin(), v.rend());
		auto cal1 = [&]
			{
				int idx = 0, cnt = 0;
				while (cnt < pivot)
				{
					if (a1[v[idx].second])
					{
						idx++;
						continue;
					}
					suma1 += v[idx].first;
					a1[v[idx].second] = v[idx].first;
					idx++;
					cnt++;
				}
				while (idx < n)
				{
					if (a1[v[idx].second])
					{
						idx++;
						continue;
					}
					ll p = v[idx].first / 2;
					if (p == v[idx].first - p)
					{
						suma1 += p - 1;
						sumb1 += p + 1;
						a1[v[idx].second] = p - 1;
						b1[v[idx].second] = p + 1;
					}
					else
					{
						ll pb = max(p, v[idx].first - p), pa = min(p, v[idx].first - p);
						suma1 += pa;
						sumb1 += pb;
						a1[v[idx].second] = pa;
						b1[v[idx].second] = pb;
					}
					idx++;
				}
				return (suma1 > sumb1);
			};
		auto cal2 = [&]
			{
				int idx = 0, cnt = 0;
				while (cnt < pivot)
				{
					suma2 += v[idx].first;
					a2[v[idx].second] = v[idx].first;
					idx++;
					cnt++;
				}
				while (idx < n)
				{
					ll p = v[idx].first / 2;
					if (p == v[idx].first - p)
					{
						suma2 += p - 1;
						sumb2 += p + 1;
						a2[v[idx].second] = p - 1;
						b2[v[idx].second] = p + 1;
					}
					else
					{
						ll pb = max(p, v[idx].first - p), pa = min(p, v[idx].first - p);
						suma2 += pa;
						sumb2 += pb;
						a2[v[idx].second] = pa;
						b2[v[idx].second] = pb;
					}
					idx++;
				}
				return (suma2 > sumb2);
			};
		if (cal1())
		{
			cout << "YES" << '\n';
			for (auto& i : a1)
			{
				cout << i << ' ';
			}
			cout << '\n';
			for (auto& i : b1)
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
		else if (cal2())
		{
			cout << "YES" << '\n';
			for (auto& i : a2)
			{
				cout << i << ' ';
			}
			cout << '\n';
			for (auto& i : b2)
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}