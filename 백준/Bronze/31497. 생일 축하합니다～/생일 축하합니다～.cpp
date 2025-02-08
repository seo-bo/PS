#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v;
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}
	string result;
	for (auto& i : v)
	{
		vector<int>check(2);
		for (int k = 0; k < 2; ++k)
		{
			int x = 0;
			cout << "?" << " " << i << "\n";
			cout.flush();
			cin >> check[k];
		}
		if (check[0] != check[1])
		{
			result = i;
		}
		if (check[0] && check[1])
		{
			cout << "!" << " " << i << "\n";
			cout.flush();
			return 0;
		}
	}
	cout << "!" << " " << result << "\n";
	cout << flush;
	return 0;
}