import sys
input = sys.stdin.readline
n = int(input().strip())
v = list(map(int,input().strip().split()))
ans = [-1] * n
stack = []
idx = n-1
for i in v[::-1]:
    while stack and stack[-1] <= i:
        stack.pop()
    if stack:
        ans[idx] = stack[-1]
    idx -= 1
    stack.append(i)
print(*ans)