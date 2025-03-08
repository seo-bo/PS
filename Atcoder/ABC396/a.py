import sys
from collections import defaultdict
input = sys.stdin.readline
n = int(input().strip())
v = list(map(int,input().split()))
for i in range(n-2):
    if v[i] == v[i+1] == v[i+2]:
        print("Yes")
        sys.exit(0)
print("No")
