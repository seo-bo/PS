#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(auto & i : queries)
    {
        swap(arr[i[0]],arr[i[1]]);
    }
    return arr;
}