#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(auto & i : queries)
    {
        int a = INT_MAX;
        for(int j = i[0]; j<=i[1];++j)
        {
            if(arr[j] > i[2])
            {
                a = min(a,arr[j]);
            }
        }
        if(a == INT_MAX)
        {
            answer.push_back(-1);
            continue;
        }
        answer.push_back(a);
    }
    return answer;
}