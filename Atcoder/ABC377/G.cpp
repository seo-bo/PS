#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	struct Trie
	{
		vector<pair<Trie*, int>>v;
		Trie() : v(26, make_pair(nullptr, 1e9)) {};
	};
	Trie* root = new Trie();
	int n = 0;
	cin >> n;
	auto insert = [&](string str)
		{
			int res = str.size();
			Trie* node = root;
			for (int i = 0; i < str.size(); ++i)
			{
				int a = str[i] - 'a';
				if (node->v[a].first == nullptr)
				{
					node->v[a].first = new Trie();
				}
				res = min(res, node->v[a].second + (int)str.size() - i - 1);
				node->v[a].second = min(node->v[a].second, (int)str.size() - i - 1);
				node = node->v[a].first;
			}
			return res;
		};
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		cout << insert(str) << '\n';
	}
	return 0;
}
