# 친구 코드 대신 봐주기
import sys
from collections import deque
input=sys.stdin.readline
N,M,K=map(int,input().strip().split())
graph=[[] for _ in range (N+1)]
S,D=map(int,input().strip().split())
for _ in range(M):
    a,b,c=map(int,input().strip().split())
    graph[a].append((c,b))
    graph[b].append((c,a))
visit=[[float('inf')]*(N+1) for _ in range(N+1)]
visit[S][0]=0
q= deque([(0,0,S)])
while q:
    w,d,v= q.popleft()
    if visit[v][d]<w:
        continue
    for nw,nv in graph[v]:
        if d+1<=N and visit[nv][d+1]>w+nw:
            visit[nv][d+1]=w+nw
            q.append((visit[nv][d+1],d+1,nv))
visit=visit[D]
print(min(visit))
for _ in range(K):
    x=int(input().strip())
    for i in range(1,N+1):
        visit[i]+=i*x
    print(min(visit))