import sys
from collections import deque
input = sys.stdin.readline
vertex,edge = map(int,input().split())
graph = [[] for i in range(vertex+1)]
degree = [0 for i in range(vertex+1)]
dp = [0 for i in range(vertex+1)]
dq = deque([])
for i in range(edge):
    a, b = map(int,input().split())
    graph[a].append(b)
    degree[b] += 1
for i in range (1, vertex+1):
    if(degree[i] == 0):
        dq.append(i)
        dp[i] = 1
while(len(dq) != 0):
    current = dq.popleft()
    for i in graph[current]:
        dp[i] = max(dp[i], dp[current] + 1)
        degree[i] -= 1
        if(degree[i] == 0):
            dq.append(i)
for i in range(1,vertex+1):
    print(dp[i], end = " ")