#include <string>
#include <vector>
#define MOD 1234567
using namespace std;
typedef long long ll;
long long solution(int n) {
    long long answer = 0;
    vector<int>dp(n+1,0);
    dp[1] = 1, dp[2] = 2;
    for(int i =3; i<=n;++i)
    {
        dp[i] = (dp[i] + dp[i-2] + dp[i-1]) % MOD;
    }
    return dp[n];
}