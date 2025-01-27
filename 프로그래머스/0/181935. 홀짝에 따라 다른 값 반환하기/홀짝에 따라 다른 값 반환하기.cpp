#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i =1; i<=n;++i)
    {
        if((n & 1) && (i & 1))
        {
            answer += i;
        }
        else if((n&1) ==0 && (i&1) == 0)
        {
            answer += i * i;
        }
    }
    return answer;
}