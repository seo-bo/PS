import sys
input = sys.stdin.readline
n = int(input().strip())
if n == 1:
    print(0)
    sys.exit(0)
elif n == 2:
    print(1)
    sys.exit(0)
t = 0
cur = 1
for i in range(3, n+1):
    cost = -1
    if t == 1:
        cost = 1
    cur = cur * 2 + cost
    t = (t + 1) % 2
print(cur)