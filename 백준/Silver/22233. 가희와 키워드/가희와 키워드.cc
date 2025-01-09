#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	unordered_set<string>s;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < k; ++i)
	{
		string temp;
		cin >> temp;
		stringstream ss(temp);
		string str;
		while (getline(ss, str, ','))
		{
			if (s.find(str) != s.end())
			{
				s.erase(str);
			}
		}
		cout << s.size() << '\n';
	}
	return 0;
}