#include <string>
#include <vector>

using namespace std;

vector<bool>visited;

void dfs(vector<vector<int>> computers, int start = 0)
{
    visited[start] = true;
    for (int i =0; i<computers[start].size();++i)
    {
        if(computers[start][i] && !visited[i])
        {
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    visited.resize(n,false);
    for (int i =0; i<n;++i)
    {
        if(!visited[i])
        {
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}
