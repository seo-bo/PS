#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<string, string> parent;
unordered_map<string,int> net;

string find(string root)
{
	if (parent[root] == root)
	{
		return root;
	}
	return parent[root] = find(parent[root]);
}

void Union(string x, string y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		if (net[x] < net[y])
		{
			swap(x, y);
		}
		parent[y] = x;
		net[x] += net[y];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 0;
	cin >> test;
	while (test--)
	{
		int num = 0;
		cin >> num;
		
		for (int i = 0; i < num; i++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			if (parent.find(str1) == parent.end()) 
			{
				parent[str1] = str1;
				net[str1] = 1;
			}
			if (parent.find(str2) == parent.end()) 
			{
				parent[str2] = str2;
				net[str2] = 1;
			}
			Union(str1, str2);
			cout << net[find(str1)] << "\n";
		}
		unordered_map<string, string>().swap(parent);
		unordered_map<string, int>().swap(net);
	}
}
