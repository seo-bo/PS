#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> temp = arr;
    if(arr.size() == 1)
    {
        return vector<int>() = {-1};
    }
    sort(temp.begin(),temp.end());
    bool flag = false;
    for(auto & i :arr)
    {
        if(i ==temp[0])
        {
            if(!flag)
            {
                flag= true;
                continue;
            }
        }
        answer.push_back(i);
    }
    return answer;
}