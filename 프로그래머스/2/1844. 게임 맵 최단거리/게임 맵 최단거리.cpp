#include<vector>
#include<queue>
#include<utility>
#include<climits>
using namespace std;
typedef pair<int,int> pii;

int solution(vector<vector<int> > maps)
{
    int answer = 0, n = maps.size(),m = maps[0].size();
    queue<pii>q;
    q.push(make_pair(0,0));
    vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
    visited[0][0] = 1;
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty())
    {
        auto [x,y] = q.front();
        if(x == n -1 && y == m-1)
        {
            return visited[x][y];
        }
        q.pop();
        for(int i =0; i<4;++i)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >=0 && nx < n && ny >=0 && ny < m && maps[nx][ny])
            {
                if(visited[nx][ny] > visited[x][y] + 1)
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    return -1;
}