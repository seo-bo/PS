import sys
input = sys.stdin.readline
h, y= map(int,input().strip().split())
dp = [0] * 13
dp[0] = h
for i in range(1,y+1):
    dp[i] = max(dp[i],int(dp[i-1] * 1.05))
    if i >= 3:
        dp[i] = max(dp[i],int(dp[i-3] * 1.20))
    if i >= 5:
        dp[i] = max(dp[i],int(dp[i-5] * 1.35))
print(dp[y])