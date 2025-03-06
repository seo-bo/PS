#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solution(int x, int y, int n) {
    int answer = 0;
    unordered_map<int,int>visited;
    queue<ll>q;
    q.push(x);
    while(!q.empty())
    {
        ll cur= q.front();
        q.pop();
        if(cur == y)
        {
            return visited[cur];
        }
        if(cur * 3 <= y)
        {
           if(visited.find(cur * 3) == visited.end())
            {
                visited[cur * 3] = visited[cur] + 1;
               q.push(cur * 3);
            }
            else if(visited[cur * 3] > visited[cur] + 1)
            {
                visited[cur * 3] = visited[cur] + 1;
                q.push(cur * 3);
            } 
        }
        if(cur * 2 <= y)
        {
           if(visited.find(cur * 2) == visited.end())
            {
                visited[cur * 2] = visited[cur] + 1;
               q.push(cur * 2);
            }
            else if(visited[cur * 2] > visited[cur] + 1)
            {
                visited[cur * 2] = visited[cur] + 1;
                q.push(cur * 2);
            } 
        }
        if(cur + n <= y)
        {
            if(visited.find(cur+n) == visited.end())
            {
                visited[cur+n] = visited[cur] + 1;
                q.push(cur +n);
            }
            else if(visited[cur+n] > visited[cur] + 1)
            {
                visited[cur+n] = visited[cur] + 1;
                q.push(cur +n);
            }
        }
    }
    return -1;
    return answer;
}