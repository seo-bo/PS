#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

unordered_map<char, int>Alpha;
vector<unordered_map<char, int>>v[29];
vector<pair<char, int>>ele[29];
vector<char>graph[29];
vector<char>nocycle, cycle;
int indegree[29] = { 0, };
bool visited[29] = { 0, };
int vertex = 0;
char pre = '[';

void input()
{
	for (int i = 0; i < 26; ++i)
	{
		Alpha[(char)(i + 'a')] = i;
	}
	Alpha['['] = 26;
	Alpha[']'] = 27;
	Alpha['-'] = 28;
	for (int i = 0; i < 29; ++i)
	{
		v[i].push_back(unordered_map<char, int>());
		indegree[i] = 50;
	}
}

void topo_sort()
{
	queue<char>q;
	for (int i = 0; i < 29; ++i)
	{
		if (!indegree[i])
		{
			if (i == 26)
			{
				q.push('[');
			}
			else if (i == 27)
			{
				q.push(']');
			}
			else if (i == 28)
			{
				q.push('-');
			}
			else
			{
				q.push((char)i + 'a');
			}
		}
	}
	while (!q.empty())
	{
		char cur = q.front();
		q.pop();
		nocycle.push_back(cur);
		for (auto& i : graph[Alpha[cur]])
		{
			if (!(--indegree[Alpha[i]]))
			{
				q.push(i);
			}
		}
	}
}

void dfs()
{
	for (auto& i : graph[Alpha[pre]])
	{
		if (!visited[Alpha[i]] && indegree[Alpha[i]] && indegree[Alpha[i]] != 50)
		{
			visited[Alpha[i]] = true;
			cycle.push_back(i);
			pre = i;
			dfs();
		}
	}
}

int main(void) // ( '[' = 26 / ']' = 27 / '-' 28 )
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	ll N = 0, K = 0, M = 0;
	cin >> N >> K >> M;
	K--;
	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		int siz = str.length();
		for (int j = 0; j < siz - 1; ++j)
		{
			v[Alpha[str[j]]][0][str[j + 1]]++;
		}
	}
	for (int i = 0; i < 29; ++i)
	{
		for (auto& k : v[i][0])
		{
			ele[i].push_back(make_pair(k.first, k.second));
		}
		sort(ele[i].begin(), ele[i].end(), [](const pair<char, int>& a, const pair<char, int>& b)
			{
				if (a.second == b.second)
				{
					return a.first < b.first;
				}
				return a.second > b.second;
			});
	}
	indegree[Alpha[pre]] = 0;
	while (1)
	{
		if (ele[Alpha[pre]].empty())
		{
			break;
		}
		char temp = ele[Alpha[pre]].front().first;
		graph[Alpha[pre]].push_back(temp);
		indegree[Alpha[temp]] = (indegree[Alpha[temp]] + 1) % 50;
		if (indegree[Alpha[temp]] == 2)
		{
			break;
		}
		pre = temp;
	}
	topo_sort();
	pre = nocycle.back();
	dfs();
	if (cycle.empty())
	{
		while (M > 0)
		{
			if (K > ((ll)nocycle.size() - 1))
			{
				cout << '.';
			}
			else
			{
				cout << nocycle[K];
			}
			K++;
			M--;
		}
	}
	else
	{
		
		while (M > 0)
		{
			while (K < (ll)nocycle.size() && M > 0)
			{
				cout << nocycle[K];
				K++;
				M--;
			}
			K -= (ll)nocycle.size();
			ll idx = K % (ll)cycle.size();
			while (M > 0)
			{
				cout << cycle[idx];
				idx = (idx + 1) % (ll)cycle.size();
				M--;
			}
		}
	}
	return 0;
}