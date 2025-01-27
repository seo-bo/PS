#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    for(auto & i : indices)
    {
        my_string[i] = '?';
    }
    for(auto & i :my_string)
    {
        if(i == '?')
        {
            continue;
        }
        answer += i;
    }
    return answer;
}