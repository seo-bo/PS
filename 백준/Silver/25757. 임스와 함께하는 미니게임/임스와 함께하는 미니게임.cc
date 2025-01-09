#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	unordered_set<string>s;
	unordered_map<char, int>mm = { {'Y',1}, {'F',2},{'O',3} };
	int n = 0;
	char a;
	cin >> n >> a;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	cout << s.size() / mm[a];
	return 0;
}