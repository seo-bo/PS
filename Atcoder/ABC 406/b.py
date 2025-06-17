import sys
input = sys.stdin.readline
n,k = map(int,input().strip().split())
v = list(map(int,input().strip().split()))
ok = 10 ** k
base = 1
for i in v:
    base *= i
    if base >= ok:
        base = 1
print(base)
