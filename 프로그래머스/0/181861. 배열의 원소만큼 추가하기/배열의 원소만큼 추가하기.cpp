#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(auto & i : arr)
    {
        for(int j =0; j<i;++j)
        {
            answer.push_back(i);
        }
    }
    return answer;
}