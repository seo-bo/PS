#include <string>
#include <vector>

using namespace std;
typedef long long ll;
long long solution(int a, int b) {
    long long answer = 0;
    for (ll i = min(a,b); i<=max(a,b);++i)
    {
        answer += i;
    }
    return answer;
}