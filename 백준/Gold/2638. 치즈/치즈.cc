#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<long,long>pll;

int main(void)
{
	int n =0 , m = 0, cnt = 0;
	cin >> n >> m;
	vector<vector<int>>v(n,vector<int>(m,0));
	vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
	for(int i =0; i<n;++i)
	{
		for(int j =0; j<m;++j)
		{
			cin >> v[i][j];
			cnt += v[i][j];
		}
	}
	auto bfs = [&]
	{
		vector<vector<int>>visited(n,vector<int>(m,0));
		visited[0][0] = true;
		queue<pii>q;
		q.push(make_pair(0,0));
		while(!q.empty())
		{
			auto [x,y] = q.front();
			q.pop();
			for(int i =0; i<4;++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if(nx >=0 && nx < n && ny>=0 && ny < m)
				{
					if(!v[nx][ny])
					{
						if(!visited[nx][ny])
						{
							visited[nx][ny] = 1;
							q.push(make_pair(nx,ny));
						}
					}
					else
					{
						visited[nx][ny]++;
					}
				}
			}
		}
		for(int i = 0; i<n;++i)
		{
			for(int j =0; j<m;++j)
			{
				if(v[i][j] && visited[i][j] >=2)
				{
					v[i][j] = 0;
					cnt--;
				}
			}
		}
	};
	for(int i =0;;++i)
	{
		if(!cnt)
		{
			cout << i;
			return 0;
		}
		bfs();
	}
	return 0;
}
