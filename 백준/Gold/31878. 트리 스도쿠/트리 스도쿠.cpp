#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>graph[111255];
bool visited[111255] = { false, };
map<ll, ll>vertex;
vector<ll>v;
int result[111255] = { 0, };

void bfs()
{
	int idx = 0;
	queue<int>q;
	visited[1] = true;
	result[1] = vertex[v[idx++]];
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (!visited[i])
			{
				result[i] = vertex[v[idx++]];
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main(void) // 실패하는 경우의 수가 없지않나?
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	v.resize(N);
	for (int i = 1; i <= N; ++i)
	{
		cin >> v[i - 1];
		vertex[v[i - 1]] = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	bfs();
	cout << "YES" << "\n";
	for (int i = 1; i <= N; ++i) // 벡터에 넣어줘서 틀렸는데, 정점이 항상 순서대로 연결되어 있진 않을듯?
	{
		cout << result[i] << " ";
	}
	return 0;
}