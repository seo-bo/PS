#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class ahoCorasick //https ://github.com/seo-bo/Algorithm_templates/blob/main/ahoCorasick.cpp
{
private:
	struct Node
	{
		map<char, Node*>child;
		Node* fail;
		vector<int> out;
		Node() { fail = nullptr; }
	};
	Node* root;
	bool built;
	void add(const string& word, int id)
	{
		Node* cur = root;
		for (auto& i : word)
		{
			if (cur->child.find(i) == cur->child.end())
			{
				cur->child[i] = new Node();
			}
			cur = cur->child[i];
		}
		cur->out.push_back(id);
	}
	void build_pattern()
	{
		queue<Node*>q;
		root->fail = root;
		for (auto& [a, b] : root->child)
		{
			b->fail = root;
			q.push(b);
		}
		while (!q.empty())
		{
			Node* cur = q.front();
			q.pop();
			for (auto& [a, b] : cur->child)
			{
				Node* f = cur->fail;
				while (f != root && f->child.find(a) == f->child.end())
				{
					f = f->fail;
				}
				if (f->child.find(a) == f->child.end())
				{
					b->fail = root;
				}
				else
				{
					b->fail = f->child[a];
				}
				b->out.insert(b->out.end(), b->fail->out.begin(), b->fail->out.end());
				q.push(b);
			}
		}
	}
	vector<pair<int, int>> search(const string& word)
	{
		vector<pair<int, int>>ans;
		Node* cur = root;
		for (int i = 0; i < (int)word.size(); ++i)
		{
			char ok = word[i];
			while (cur != root && cur->child.find(ok) == cur->child.end())
			{
				cur = cur->fail;
			}
			if (cur->child.find(ok) != cur->child.end())
			{
				cur = cur->child[ok];
			}
			for (auto& j : cur->out)
			{
				ans.push_back(make_pair(j, i));
			}
		}
		return ans;
	}
public:
	ahoCorasick() { root = new Node(); built = false; }
	void insert(const string& word, int id)
	{
		add(word, id);
	}
	vector<pair<int, int>> find(const string& word)
	{
		if (!built)
		{
			build_pattern();
			built = true;
		}
		return search(word);
	}
};

typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		if (!n && !m)
		{
			break;
		}
		ahoCorasick aho;
		vector<string>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
			aho.insert(v[i], i);
		}
		cin.ignore();
		int ans = 0;
		for (int i = 1; i <= m; ++i)
		{
			string str;
			getline(cin, str);
			vector<pii>ok = aho.find(str);
			for (auto& [a, b] : ok)
			{
				a = b - (int)v[a].size() + 1;
			}
			sort(ok.begin(), ok.end(), [&](const pii& a, const pii& b)
				{
					return a.second < b.second;
				});
			int now = INT_MIN;
			for (auto& [a, b] : ok)
			{
				if (now < a)
				{
					ans++;
					now = b;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}