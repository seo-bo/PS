#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto & i :my_string)
    {
        if('a' <= i && i <= 'z')
        {
            answer += char(i + -'a' + 'A');
        }
        else
        {
            answer += char(i - 'A' + 'a');
        }
    }
    return answer;
}