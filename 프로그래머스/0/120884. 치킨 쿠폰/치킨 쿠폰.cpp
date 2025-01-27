#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0, c = chicken;
    while (c >= 10)
    {
        int pivot = c /10;
        answer += pivot;
        c %= 10;
        c += pivot;
    }
    return answer;
}