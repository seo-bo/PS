#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(auto & i : arr)
    {
        if(answer.empty())
        {
            answer.push_back(i);
        }
        else if(answer.back() == i)
        {
            answer.pop_back();
        }
        else
        {
            answer.push_back(i);
        }
    }
    if(answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}