#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(auto &i : strArr)
    {
        if(i.find("ad") == string::npos)
        {
            answer.push_back(i);
        }
    }
    return answer;
}