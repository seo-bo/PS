#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int n = arr1.size(), m = arr1[0].size();
    for(int i =0; i<n; ++i)
    {
        for(int j =0; j<m;++j)
        {
            arr1[i][j] += arr2[i][j];
        }
    }
    return arr1;
}