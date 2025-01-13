import sys
input = sys.stdin.readline
ans = 0
for i in range(10):
    a = int(input().strip())
    if a == 1:
        ans = (ans + 90) % 360
    elif a == 3:
        ans = (ans + 270) % 360
    else:
        ans = (ans + 180) % 360
if ans == 0:
    print("N")
elif ans == 90:
    print("E")
elif ans == 180:
    print("S")
else:
    print("W")