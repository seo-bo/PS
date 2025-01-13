import sys
input = sys.stdin.readline
q = int(input().strip())
dir = [[-1,0],[0,-1],[0,1],[1,0]]
for i in range(q):
    ans ,ax ,ay = 0,0,0
    n,m = map(int,input().strip().split())
    v = [input().strip() for _ in range(n)]
    for j in range(n):
        for k in range(m):
            if v[j][k] != '#':
                pivot = 1
                for _ in range(4):
                    x ,y = j + dir[_][0], k + dir[_][1]
                    while 0 <= x < n and 0 <= y < m and v[x][y] != '#':
                        if v[x][y] == "@":
                            pivot += 1
                        x += dir[_][0]
                        y += dir[_][1]
                if ans < pivot:
                    ax ,ay = j, k
                    ans = pivot
    print(f"{ax}, {ay}")