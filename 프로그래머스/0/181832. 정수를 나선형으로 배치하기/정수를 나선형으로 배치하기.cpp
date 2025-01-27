#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n,vector<int>(n,0));
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int d = 0, x = 0, y = 0, cnt = 1;
    while(cnt <= n * n)
    {
        answer[x][y] = cnt++;
        visited[x][y] = true;
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if(nx >=0 && nx < n && ny >=0 && ny < n && !visited[nx][ny])
        {
            x = nx;
            y = ny;
        }
        else
        {
            d = (d+1) % 4;
            x = x + dir[d][0];
            y = y + dir[d][1];
        }    
    }
    return answer;
}