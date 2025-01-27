#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string temp = "";
    for(auto & i : myStr)
    {
        if(i == 'a' || i == 'b' || i == 'c')
        {
            if(temp.empty())
            {
                continue;
            }
            answer.push_back(temp);
            temp = "";
        }
        else
        {
            temp += i;   
        }
    }
    if(!temp.empty())
    {
        answer.push_back(temp);
    }
    if(answer.empty())
    {
        answer.push_back("EMPTY");
    }
    return answer;
}