#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double lb;

bool fail = false;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, stair = 0;
	ll hp = 0;
	cin >> num >> stair >> hp;
	vector<ll>v(stair);
	for (int i = 0; i < num; ++i)
	{
		int item = 0;
		for (int j = 0; j < stair; ++j)
		{
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		for (auto& i : v)
		{
			if (i == -1)
			{
				item++;
				continue;
			}
			if (hp >= i)
			{
				hp += i;
			}
			else
			{
				if (item)
				{
					while (hp < i && item)
					{
						hp *= 2;
						item--;
					}
					if (hp >= i)
					{
						hp += i;
					}
					else
					{
						fail = true;
					}
				}
				else
				{
					fail = true;
				}
			}
			if (fail)
			{
				break;
			}
		}
		while (item)
		{
			hp *= 2;
			item--;
		}
		vector<ll>(stair).swap(v);
	}
	if (fail)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	return 0;
}