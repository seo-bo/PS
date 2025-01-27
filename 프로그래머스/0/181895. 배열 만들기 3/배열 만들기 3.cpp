#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for(auto & i : intervals)
    {
        for(int j = i[0]; j <= i[1];++j)
        {
            answer.push_back(arr[j]);
        }
    }
    return answer;
}