#include <string>
#include <vector>
#define MOD 1234567
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>v(n+1,0);
    v[0] = 0, v[1] = 1;
    for(int i = 2; i<=n;++i)
    {
        v[i] = (v[i-1] + v[i-2]) % MOD;
    }
    return v[n];
}