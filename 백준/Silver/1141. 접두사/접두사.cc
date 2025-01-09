#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<string>v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	int result = N;
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (v[i].length() > v[j].length())
			{
				break;
			}
			auto it = mismatch(v[i].begin(), v[i].end(), v[j].begin());
			if (it.first == v[i].end())
			{
				result--;
				break;
			}
		}
	}
	cout << result;
	return 0;
}
