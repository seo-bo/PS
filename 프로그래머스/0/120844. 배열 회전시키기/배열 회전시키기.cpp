#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    deque<int>dq;
    for(auto & i :numbers)
    {
        dq.push_back(i);
    }
    if(direction == "left")
    {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    else
    {
        dq.push_front(dq.back());
        dq.pop_back();
    }
    for(auto & i : dq)
    {
        answer.push_back(i);
    }
    return answer;
}