#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(auto & i :my_string)
    {
        if('1' <= i && i <='9')
        {
            answer += i - '0';
        }
    }
    return answer;
}