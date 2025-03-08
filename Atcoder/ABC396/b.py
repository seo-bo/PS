import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
dq = deque([])
for i in range(100):
    dq.append(0)
q = int(input().strip())
for _ in range(q):
    data = list(map(int,input().strip().split()))
    if data[0] == 1:
        dq.appendleft(data[1])
    else:
        print(dq.popleft())
