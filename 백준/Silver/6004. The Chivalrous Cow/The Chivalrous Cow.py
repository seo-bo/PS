import sys
from collections import deque
input = sys.stdin.readline
m, n = map(int,input().strip().split())
v = [input().strip() for _ in range(n)]
visited = [[float('inf') for _ in range(m)]for _ in range(n)]
sx ,sy = 0, 0
for i in range(n):
    for j in range(m):
        if v[i][j] == "K":
            sx ,sy = i,j
            break
q = deque([])
q.append((sx,sy))
visited[sx][sy] = 0
dir = [[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2],[-2,-1]]
while q:
    x,y = q.popleft()
    if v[x][y] == "H":
        print(visited[x][y])
        sys.exit(0)
    for dx,dy in dir:
        nx = x + dx
        ny = y + dy
        if 0<=nx <n and 0 <= ny < m and v[nx][ny] != "*":
            cost = visited[x][y] +1
            if visited[nx][ny] > cost:
                visited[nx][ny] = cost
                q.append((nx,ny))