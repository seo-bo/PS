#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0, base = 1;
    vector<int>s;
    for(auto & i : order)
    {
        while(base <= i)
        {
            s.push_back(base++);
        }
        if(!s.empty() && s.back() == i)
        {
            s.pop_back();
            answer++;
        }
        else
        {
            break;
        }
    }
    return answer;
}