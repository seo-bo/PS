#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int solution(int balls, int share) {
    ll ans = 1;
    for(ll i =0; i<share;++i)
    {
        ans *= balls - i;
        ans /= i + 1LL;
    }
    return (int)ans;
}