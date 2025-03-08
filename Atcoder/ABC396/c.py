import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().strip().split())
a = list(map(int,input().strip().split()))
a.sort(reverse=True)
__ = list(map(int,input().strip().split()))
b = []
for i in __:
    if i > 0:
        b.append(i)
b.sort(reverse=True)
ln = len(b)
prea = [0 for _ in range(n+1)]
preb = [0 for _ in range(ln+1)]
pivot = 0
for i in range(1,n+1):
    prea[i] = prea[i-1] + a[i-1]
    if a[i-1] > 0:
        pivot += 1
for i in range(1,ln+1):
    preb[i] = preb[i-1] + b[i-1]
ans = 0
lim = min(ln,n)
for i in range(0,lim+1):
    temp = prea[i]
    if i <= pivot:
        temp = prea[pivot]
    ans = max(ans, temp + preb[i])
print(ans)
