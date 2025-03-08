import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().strip().split())
v = list(map(int,input().strip().split()))
BIT = [0 for _ in range(m+1)]
ans = [0 for _ in range(m)]
temp = [[] for _ in range(m)]
for i in range(n):
    temp[v[i]].append(i+1)
def update (idx, delta):
    while idx <= m:
        BIT[idx] += delta
        idx += idx & -idx
def query (idx):
    res = 0
    while idx:
        res += BIT[idx]
        idx -= idx & -idx
    return res
for i in v:
    ans[0] += query(m) - query(i+1)
    update(i+1,1)
now = ans[0]
for i in range(m - 1):
    pivot = 0
    for j in temp[m - i - 1]:
        pivot += 2 * j - n - 1
    now += pivot
    ans[i+1] = now
for i in ans:
    print(i)
