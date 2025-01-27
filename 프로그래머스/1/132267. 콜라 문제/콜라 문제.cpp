#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a)
    {
        int pivot = (n /a) * b;
        answer += pivot;
        n %= a;
        n += pivot;
    }
    return answer;
}