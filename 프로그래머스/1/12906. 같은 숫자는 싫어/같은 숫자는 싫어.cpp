#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int pre = -1;
    for(auto & i : arr)
    {
        if(pre == i)
        {
            continue;
        }
        answer.push_back(i);
        pre = i;
    }
    return answer;
}