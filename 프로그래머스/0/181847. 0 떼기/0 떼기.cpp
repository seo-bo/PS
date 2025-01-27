#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    bool flag = true;
    for(auto & i : n_str)
    {
        if(i != '0')
        {
            flag = false;
        }
        if(!flag)
        {
            answer += i;
        }
    }
    return answer;
}