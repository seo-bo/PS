#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for(auto & i : rny_string)
    {
        if (i == 'm')
        {
            answer += "rn";
            continue;
        }
        answer += i;
    }
    return answer;
}