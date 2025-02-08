#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		string str, temp;
		getline(cin, str);
		map<string, bool>mm;
		vector<string>ans;
		stringstream ss(str);
		while (ss >> temp)
		{
			mm[temp] = true;
			ans.push_back(temp);
		}
		while (getline(cin, str))
		{
			if (str.empty())
			{
				continue;
			}
			vector<string>tt;
			stringstream ss2(str);
			while (ss2 >> temp) 
			{
				tt.push_back(temp);
			}
			if (tt.size() == 3)
			{
				mm[tt[2]] = false;
			}
			else if (tt.size() == 5)
			{
				for (auto& i : ans)
				{
					if (mm[i])
					{
						cout << i << ' ';
					}
				}
				cout << '\n';
				break;
			}
		}
	}
	return 0;
}