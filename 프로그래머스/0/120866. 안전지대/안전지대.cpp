#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<bool>>v(n, vector<bool>(n,true));
    vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for(int i =0; i<n;++i)
    {
        for(int j =0; j<n; ++j)
        {
            if(board[i][j] == 1)
            {
                v[i][j] = false;
                for(int k =0; k<8;++k)
                {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if (nx >=0 && nx < n && ny >=0 && ny < n)
                    {
                        v[nx][ny] = false;
                    }
                }
            }
        }
    }
    int answer = 0;
    for(int i =0; i<n;++i)
    {
        for(int j =0; j <n;++j)
        {
            if(v[i][j])
            {
                answer++;
            }
        }
    }
    return answer;
}