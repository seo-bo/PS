import sys
input = sys.stdin.readline
ed = 1000000
n = int(input().strip())
prefix = [0 for _ in range(ed+10)]
for i in range(n):
    start, end = map(int,input().strip().split())
    prefix[start] += 1
    prefix[end+1] -= 1
for i in range(1, ed+5):
    prefix[i] += prefix[i-1]
q = int(input().strip())
v = list(map(int,input().strip().split()))
for i in v:
    print(prefix[i])