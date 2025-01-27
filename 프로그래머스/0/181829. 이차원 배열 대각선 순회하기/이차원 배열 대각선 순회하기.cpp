#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    for(int i =0 ;i<n;++i)
    {
        for(int j =0; j<m;++j)
        {
            if(i +j <=k)
            {
                answer += board[i][j];
            }
        }
    }
    return answer;
}