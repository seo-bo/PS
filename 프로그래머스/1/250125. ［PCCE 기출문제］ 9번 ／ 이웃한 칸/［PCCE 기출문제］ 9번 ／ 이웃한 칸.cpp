#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
    for(int i =0; i<4;++i)
    {
        int nx = h + dir[i][0];
        int ny = w + dir[i][1];
        if (nx >=0 && nx < n && ny >=0 && ny < n)
        {
            if(board[h][w] == board[nx][ny])
            {
                answer++;
            }
        }
    }
    return answer;
}