#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	struct Trie
	{
		vector<Trie*>child;
		bool check;
		Trie() : check(false), child(10, nullptr) {}
	};
	auto insert = [&](Trie* root, string& word)
		{
			Trie* node = root;
			bool c = false;
			for (auto& i : word)
			{
				if (node->check)
				{
					return false;
				}
				int idx = i - '0';
				if (!node->child[idx])
				{
					node->child[idx] = new Trie();
					c = true;
				}
				node = node->child[idx];
			}
			node->check = true;
			return c;
		};
	int T = 0;
	cin >> T;
	while (T--)
	{
		Trie* root = new Trie();
		int n = 0;
		cin >> n;
		vector<string>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		bool check = true;
		sort(v.begin(), v.end());
		for (auto& i : v)
		{
			if (!insert(root, i))
			{
				check = false;
				break;
			}
		}
		cout << ((check) ? "YES" : "NO") << '\n';
	}
	return 0;
}