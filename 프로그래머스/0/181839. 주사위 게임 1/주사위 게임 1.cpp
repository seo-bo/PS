#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    if((a&1) && (b&1))
    {
        return a * a + b * b;
    }
    else if((a & 1) == 0 && (b & 1) == 0)
    {
        return abs(a - b);
    }
    else
    {
        return 2 *(a+b);
    }
    return answer;
}