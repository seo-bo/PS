import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().strip().split())
sys.setrecursionlimit(n+10)
graph = defaultdict(list)
for i in range(m):
    a,b,c = map(int,input().strip().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
visited = [False for _ in range(n+1)]
ans = [1<< 62]
def dfs(cur, sum):
    if cur == n:
        ans[0] = min(ans[0], sum)
        return
    for a,b in graph[cur]:
        if not visited[a]:
            visited[a] = True
            dfs(a, sum ^ b)
            visited[a] = False
visited[1] = True
dfs(1,0)
print(ans[0])
