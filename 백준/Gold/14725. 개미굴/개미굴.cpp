#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	struct Trie
	{
		map<string, Trie*> child;
	};
	function<void(Trie*, vector<string>&)> insert = [&](Trie* root, vector<string>& v)
		{
			Trie* cur = root;
			for (auto& i : v)
			{
				if (cur->child.find(i) == cur->child.end())
				{
					cur->child[i] = new Trie();
				}
				cur = cur->child[i];
			}
		};
	function<void(Trie*, int)> print = [&](Trie* root, int depth)
		{
			for (auto& [a, b] : root->child)
			{
				for (int i = 0; i < depth; ++i)
				{
					cout << "--";
				}
				cout << a << '\n';
				print(b, depth + 1);
			}
		};
	int n = 0;
	cin >> n;
	Trie* root = new Trie();
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		cin >> k;
		vector<string>v(k);
		for (auto& j : v)
		{
			cin >> j;
		}
		insert(root, v);
	}
	print(root, 0);
	return 0;
}