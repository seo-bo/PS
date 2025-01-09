#include <bits/stdc++.h>
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
	struct Trie
	{
		map<string, Trie*>child;
	};
	auto insert = [&](Trie* root, vector<string>& d)
		{
			Trie* node = root;
			for (auto& i : d)
			{
				if (node->child.find(i) == node->child.end())
				{
					node->child[i] = new Trie();
				}
				node = node->child[i];
			}
		};
	function<void(Trie*, int)>show = [&](Trie* root, int depth)
		{
			for (auto& [i, j] : root->child)
			{
				cout << string(depth, ' ') << i << '\n';
				show(j, depth + 1);
			};
		};
	int n = 0;
	cin >> n;
	cin.ignore();
	Trie* root = new Trie();
	for (int i = 0; i < n; ++i)
	{
		string temp;
		getline(cin, temp);
		vector<string>dir;
		stringstream ss(temp);
		string str;
		while (getline(ss, str, '\\'))
		{
			dir.push_back(str);
		}
		insert(root, dir);
	}
	show(root, 0);
	return 0;
}