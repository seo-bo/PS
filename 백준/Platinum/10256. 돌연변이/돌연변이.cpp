#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(char a)
{
	if (a == 'A')
	{
		return 0;
	}
	else if (a == 'C')
	{
		return 1;
	}
	else if (a == 'G')
	{
		return 2;
	}
	return 3;
}
class ahoCorasick //https ://github.com/seo-bo/Algorithm_templates/blob/main/ahoCorasick.cpp
{
private:
	struct Node
	{
		Node* child[4];
		Node* fail;
		ll out;
		Node()
		{
			fail = nullptr;
			out = 0;
			for (int i = 0; i < 4; ++i)
			{
				child[i] = nullptr;
			}
		}
	};
	Node* root;
	bool built;
	void add(const string& word)
	{
		Node* cur = root;
		for (auto& i : word)
		{
			int idx = check(i);
			if (!cur->child[idx])
			{
				cur->child[idx] = new Node();
			}
			cur = cur->child[idx];
		}
		cur->out++;
	}
	void build_pattern()
	{
		queue<Node*>q;
		root->fail = root;
		for (int i = 0; i < 4; ++i)
		{
			if (root->child[i])
			{
				root->child[i]->fail = root;
				q.push(root->child[i]);
			}
		}
		while (!q.empty())
		{
			Node* cur = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				if (!cur->child[i])
				{
					continue;
				}
				Node* temp = cur->child[i], * f = cur->fail;
				while (f != root && !f->child[i])
				{
					f = f->fail;
				}
				if (f->child[i])
				{
					temp->fail = f->child[i];
				}
				else
				{
					temp->fail = root;
				}
				temp->out += temp->fail->out;
				q.push(temp);
			}
		}
	}
	ll search(const string& word)
	{
		ll ans = 0;
		Node* cur = root;
		for (auto& i : word)
		{
			int idx = check(i);
			while (cur != root && !cur->child[idx])
			{
				cur = cur->fail;
			}
			if (cur->child[idx])
			{
				cur = cur->child[idx];
			}
			ans += cur->out;
		}
		return ans;
	}
	void destroy(Node* node)
	{
		if (!node)
		{
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			destroy(node->child[i]);
		}
		delete node;
	}
public:
	ahoCorasick() { root = new Node(); built = false; }
	~ahoCorasick()
	{
		destroy(root);
	}
	void insert(const string& word)
	{
		add(word);
	}
	ll find(const string& word)
	{
		if (!built)
		{
			build_pattern();
			built = true;
		}
		return search(word);
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		string a, b;
		cin >> a >> b;
		ahoCorasick aho;
		set<string>s;
		for (int i = 0; i < m; ++i)
		{
			for (int j = i; j < m; ++j)
			{
				string res = b;
				reverse(res.begin() + i, res.begin() + j + 1);
				if (s.find(res) != s.end())
				{
					continue;
				}
				aho.insert(res);
				s.insert(res);
			}
		}
		cout << aho.find(a) << '\n';
	}
	return 0;
}