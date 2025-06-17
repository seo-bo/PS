#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class ahoCorasick //https ://github.com/seo-bo/Algorithm_templates/blob/main/ahoCorasick.cpp
{
private:
	struct Node
	{
		vector<pair<Node*, char>>child;
		Node* fail;
		vector<int> out;
		Node() { fail = nullptr; }
	};
	Node* root;
	bool built;
	vector<string>info;
	vector<int>prefix;
	Node* getter(Node* node, char o)
	{
		for (auto& [a, b] : node->child)
		{
			if (b == o)
			{
				return a;
			}
		}
		return nullptr;
	}
	void add(const string& word, int id)
	{
		Node* cur = root;
		for (auto& i : word)
		{
			Node* nxt = getter(cur, i);
			if (!nxt)
			{
				nxt = new Node();
				cur->child.push_back(make_pair(nxt, i));
			}
			cur = nxt;
		}
		cur->out.push_back(id);
	}
	void build_pattern()
	{
		queue<Node*>q;
		root->fail = root;
		for (auto& [a, b] : root->child)
		{
			a->fail = root;
			q.push(a);
		}
		while (!q.empty())
		{
			Node* cur = q.front();
			q.pop();
			for (auto& [a, b] : cur->child)
			{
				Node* f = cur->fail;
				while (f != root && getter(f, b) == nullptr)
				{
					f = f->fail;
				}
				if (getter(f, b) != nullptr)
				{
					a->fail = getter(f, b);
				}
				else
				{
					a->fail = root;
				}
				for (auto& i : a->fail->out)
				{
					a->out.push_back(i);
				}
				q.push(a);
			}
		}
	}
	void search(const string& word)
	{
		Node* cur = root;
		for (int i = 0; i < (int)word.size(); ++i)
		{
			char ok = word[i];
			while (cur != root && getter(cur, ok) == nullptr)
			{
				cur = cur->fail;
			}
			if (getter(cur, ok) != nullptr)
			{
				cur = getter(cur, ok);
			}
			for (auto& j : cur->out)
			{
				prefix[i - (int)info[j].size() + 2]++;
				prefix[i + 2]--;
			}
		}
	}
public:
	ahoCorasick(int n, int m) { root = new Node(); built = false; prefix.resize(n + 30), info.resize(m + 1); }
	void insert(const string& word, int id)
	{
		info[id] = word;
		add(word, id);
	}
	void find(const string& word)
	{
		if (!built)
		{
			build_pattern();
			built = true;
		}
		search(word);
	}
	int res()
	{
		int n = prefix.size() - 30;
		for (int i = 1; i <= n; ++i)
		{
			prefix[i] += prefix[i - 1];
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!prefix[i])
			{
				ans++;
			}
		}
		return ans;
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	int m = 0;
	cin >> m;
	ahoCorasick aho(n, m);
	for (int i = 1; i <= m; ++i)
	{
		string temp;
		cin >> temp;
		aho.insert(temp, i);
	}
	aho.find(str);
	cout << aho.res();
	return 0;
}