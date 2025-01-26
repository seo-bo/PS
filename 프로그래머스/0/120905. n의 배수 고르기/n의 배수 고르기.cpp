#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for(auto & i : numlist)
    {
        if(i % n)
        {
            continue;
        }
        answer.push_back(i);
    }
    return answer;
}