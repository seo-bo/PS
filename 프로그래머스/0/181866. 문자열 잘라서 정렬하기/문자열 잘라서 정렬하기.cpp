#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string str = "";
    for(auto & i : myString)
    {
        if(i == 'x')
        {
            if(str != "")
            { 
                answer.push_back(str);
            }
            str = "";
            continue;
        }
        str += i;
    }
    if(str != "")
    {
        answer.push_back(str);
    }
    sort(answer.begin(),answer.end());
    return answer;
}