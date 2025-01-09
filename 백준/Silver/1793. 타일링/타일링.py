import sys
input = sys.stdin.readline
dp = [1,1,3]
for i in range(3,251):
    dp.append(dp[i-1] + 2*dp[i-2])
while True:
    n = input().strip()
    if n == "":
        break
    else:
        print(dp[int(n)])