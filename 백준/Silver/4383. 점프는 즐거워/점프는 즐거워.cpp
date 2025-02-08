#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int num = 0;
vector<ll>v;
unordered_map<ll, ll>mm;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> num)
	{
		bool fail = false;
		v.resize(num);
		for (int i = 0; i < num; ++i)
		{
			cin >> v[i];
		}
		for (int i = 0; i < num - 1; ++i)
		{
			ll temp = llabs(v[i] - v[i + 1]);
			if (!temp || temp > num - 1)
			{
				fail = true;
				break;
			}
			if (mm.find(temp) == mm.end()) // 없으면
			{
				mm.insert(make_pair(temp, 1));
			}
			else
			{
				fail = true;
				break;
			}
		}
		if (!fail)
		{
			cout << "Jolly" << "\n";
		}
		else
		{
			cout << "Not jolly" << "\n";
		}
		vector<ll>().swap(v);
		unordered_map<ll, ll>().swap(mm);
	}
	return 0;
}