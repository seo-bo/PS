dp = [0 for _ in range(5001)]
b,c,d,e = map(int,input().split())
dp[1],dp[2] = d,e
for i in range(3,5001):
    dp[i] = b * dp[i-1] + c * dp[i-2]
print(dp[5000] / dp[4999])