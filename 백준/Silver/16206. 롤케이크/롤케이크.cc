#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0;
	ll result = 0;
	cin >> N >> M;
	vector<ll>v;
	vector<ll>b;
	for (int i = 0; i < N; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (!(temp % 10))
		{
			if (temp == 10)
			{
				result++;
			}
			else
			{
				v.push_back(temp);
			}
		}
		else
		{
			b.push_back(temp);
		}
	}
	sort(v.begin(), v.end());
	sort(b.begin(), b.end());
	bool check = false;
	for (auto& i : v )
	{
		if (M <= 0)
		{
			check = true;
			break;
		}
		if (i / 10 - 1 <= M)
		{
			result += i / 10;
			M -= (i / 10 - 1);
		}
		else
		{
			result += M;
			check = true;
			break;
		}
	}
	for (auto& i : b)
	{
		if (check)
		{
			break;
		}
		if (M <= 0)
		{
			break;
		}
		if (i / 10 <= M)
		{
			result += i / 10;
			M -= i / 10;
		}
		else
		{
			result += M;
			break;
		}
	}
	cout << result;
	return 0;
}