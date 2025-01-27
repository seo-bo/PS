#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int n = arr.size(), m = arr[0].size();
    int diff = n - m;
    if(!diff)
    {
        return arr;
    }
    else if (diff > 0)
    {
        for(auto & i : arr)
        {
            for(int j =0; j<diff;++j)
            {
                i.push_back(0);
            }
            answer.push_back(i);
        }
    }
    else
    {
        answer = arr;
        for(int i =0; i < abs(diff);++i)
        {
            answer.push_back(vector<int>(m,0));
        }
    }
    return answer;
}