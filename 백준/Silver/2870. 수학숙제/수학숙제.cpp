#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void) // 1 5 9 13
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	vector<string>ans;
	auto judge = [&](string& temp)
		{
			if (temp.empty())
			{
				return;
			}
			while (temp.size() > 1 && temp[0] == '0')
			{
				temp.erase(temp.begin());
			}
			ans.push_back(temp);
			temp.clear();
		};
	while (T--)
	{
		string str, temp;
		cin >> str;
		for (auto& i : str)
		{
			if ('0' <= i && i <= '9')
			{
				temp += i;
			}
			else
			{
				judge(temp);
			}
		}
		judge(temp);
	}
	sort(ans.begin(), ans.end(), [&](const string& a, const string& b)
		{
			if (a.length() == b.length())
			{
				return a < b;
			}
			return a.length() < b.length();
		});
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}