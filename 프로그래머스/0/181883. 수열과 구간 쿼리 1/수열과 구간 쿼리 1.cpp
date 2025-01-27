#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(auto & i : queries)
    {
        for(int j = i[0]; j <=i[1];++j)
        {
            arr[j]++;
        }
    }
    return arr;
}