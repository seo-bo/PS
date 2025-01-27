#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    string str = to_string(age);
    for(auto & i : str)
    {
        int p = i - '0';
        answer += 'a' + p;
    }
    return answer;
}