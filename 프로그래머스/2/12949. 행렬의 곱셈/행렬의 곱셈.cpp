#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {  
    int r1 = arr1.size(), c1 = arr1[0].size();
    int r2 = arr2.size(), c2 = arr2[0].size();
    vector<vector<int>>answer;
    for(int i =0; i<r1;++i)
    {
        vector<int>temp;
        for(int j =0; j<c2;++j)
        {
            int t = 0;
            for(int k =0; k < c1;++k)
            {
                t += arr1[i][k] * arr2[k][j]; 
            }
            temp.push_back(t);
        }
        answer.push_back(temp);
    }
    return answer;
}