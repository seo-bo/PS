#include <string>
#include <vector>

using namespace std;
typedef long long ll;
int solution(int num) {
    int answer = -1;
    ll a = num;
    if(num == 1)
    {
        return 0;
    }
    for(int i =1; i<=600;++i)
    {
        if(a & 1)
        {
            a = a*3+1;
        }
        else
        {
            a >>=1;
        }
        if(a == 1)
        {
            return (i >500) ? -1 : i;
        }
    }
    return answer;
}