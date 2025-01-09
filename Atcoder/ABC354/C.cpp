#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

struct card
{
	int A;
	int C;
	int idx;
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	vector<card>v(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i].A >> v[i].C;
		v[i].idx = i + 1;
	}
	sort(v.begin(), v.end(), [](const card& a, const card& b)
		{
			return a.C < b.C;
		});
	vector<int> result;
	int MAX = 0;
	for (auto& i : v)
	{
		if (i.A > MAX)
		{
			result.push_back(i.idx);
			MAX = i.A;
		}
	}
	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (auto& i : result)
	{
		cout << i << " ";
	}
	return 0;

}
