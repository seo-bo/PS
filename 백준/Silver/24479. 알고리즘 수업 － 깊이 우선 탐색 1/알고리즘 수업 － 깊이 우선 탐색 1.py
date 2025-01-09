import sys
from collections import defaultdict
sys.setrecursionlimit(10**9)
def dfs(v):
    visited[v] = order[0]
    order[0] += 1
    for neighbor in sorted(graph[v]):
        if visited[neighbor] == 0:
            dfs(neighbor)

N, M, R = map(int, sys.stdin.readline().split())
graph = defaultdict(list)
visited = [0] * (N + 1)
order = [1]

for i in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

dfs(R)

for i in range(1, N + 1):
    if visited[i] != 0:
        print(visited[i])
    else:
        print(0)

# 아니, C언어로는 정렬할때 인접리스트 순회해야해서 시간초과,
# 우선순위 큐로 시간초과 해결하려니 메모리 초과???
# 억울하네 어떻게 풀러는거? ㄹㅇ?
