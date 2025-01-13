import sys
input = sys.stdin.readline
n = int(input().strip())
v = map(int,input().strip().split())
cnt = 1
stack = []
for i in v:
    while stack and stack[-1] == cnt:
        cnt += 1
        stack.pop()
    if i == cnt:
        cnt += 1
    else:
        stack.append(i)
while stack and stack[-1] == cnt:
        cnt += 1
        stack.pop()
if stack:
    print("Sad")
else:
    print("Nice")