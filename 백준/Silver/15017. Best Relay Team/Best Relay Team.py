import sys
input = sys.stdin.readline
n = int(input().strip())
v = [list(input().strip().split()) for i in range(n)]
v.sort(key = lambda x : float(x[2]))
ans = float('inf')
res = []
for i in range(n):
    name = []
    time = float(v[i][1])
    cnt = 1
    name.append(v[i][0])
    for j in range(n):
        if cnt == 4:
            break
        if v[j][0] == v[i][0]:
            continue
        time += float(v[j][2])
        cnt += 1
        name.append(v[j][0])
    if ans > time:
        res = name
        ans = time
print(ans)
print("\n".join(res))