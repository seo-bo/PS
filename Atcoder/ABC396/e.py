import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().strip().split())
graph = defaultdict(list)
for i in range(m):
    a,b,c = map(int,input().strip().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
visited = [False for _ in range(n+1)]
mid = [0 for _ in range(n+1)]
ans = [0 for _ in range(n+1)]
for i in range(1,n+1):
    if not visited[i]:
        temp = []
        q = deque([])
        visited[i] = True
        mid[i] = 0
        q.append(i)
        while q:
            cur = q.popleft()
            temp.append(cur)
            for a,b in graph[cur]:
                cost = mid[cur] ^ b
                if not visited[a]:
                    visited[a] = True
                    mid[a] = cost
                    q.append(a)
                elif mid[a] != cost:
                    print(-1)
                    sys.exit(0)
        p = 0
        for j in range(62):
            one,zero =0, 0
            for k in temp:
                if (mid[k] >> j) & 1:
                    one += 1
                    continue
                zero += 1
            if one > zero:
                p |= (1<< j)
        for j in temp:
            ans[j] = p ^ mid[j]
for i in range(1,n+1):
    print(ans[i],end = " ")
