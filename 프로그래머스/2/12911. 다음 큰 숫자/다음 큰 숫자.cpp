#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int pivot = __builtin_popcount(n);
    for(int i = n+1;;++i)
    {
        if(pivot == __builtin_popcount(i))
        {
            return i;
        }
    }
    return answer;
}