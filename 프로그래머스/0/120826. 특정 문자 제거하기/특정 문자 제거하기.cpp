#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for(auto & i : my_string)
    {
        if(i == letter[0])
        {
            continue;
        }
        answer += i;
    }
    return answer;
}