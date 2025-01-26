#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    for(auto & i : num_str)
    {
        answer += i - '0';
    }
    return answer;
}