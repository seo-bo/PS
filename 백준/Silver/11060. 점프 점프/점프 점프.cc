#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int N = 0;
vector<int>v;
int visited[1001] = {0,};

void bfs()
{
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == N-1)
		{
			return;
		}
		for (int i =1; i<=v[cur];++i)
		{
			int nx = cur + i;
			if(!visited[nx] && nx <=N-1)
			{
				visited[nx] = visited[cur] +1;
				q.push(nx);
			}
		}
	}
}



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	if (N == 1)
	{
		cout << 0;
		return 0;
	}
	v.resize(N);
	for (int i =0; i<N;++i)
	{
		cin >> v[i];
	}
	bfs();
	if(!visited[N-1])
	{
		cout << -1;
	}
	else
	{
		cout << visited[N-1];
	}
	return 0;
}

