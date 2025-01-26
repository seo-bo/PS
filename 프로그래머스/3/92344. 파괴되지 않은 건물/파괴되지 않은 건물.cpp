#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    int n = board.size(), m = board[0].size();
    vector<vector<int>>prefix(n + 3, vector<int>(m + 3, 0));
    for (auto& i : skill)
    {
        int cost = i[5];
        if (i[0] == 1)
        {
            cost = -i[5];
        }
        prefix[i[1]][i[2]] += cost;
        prefix[i[1]][i[4] + 1] -= cost;
        prefix[i[3] + 1][i[2]] -= cost;
        prefix[i[3] + 1][i[4] + 1] += cost;
    }
    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 1; j <= m + 1; ++j)
        {
            prefix[i][j] += prefix[i][j - 1];
        }
    }
    for (int i = 0; i <= m + 1; ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
        {
            prefix[j][i] += prefix[j - 1][i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] + prefix[i][j] > 0)
            {
                answer++;
            }
        }
    }
    return answer;
}