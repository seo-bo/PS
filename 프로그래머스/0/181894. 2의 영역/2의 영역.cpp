#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i =0; i<(int)arr.size();++i)
    {
        if(arr[i] == 2)
        {
            mini = min(i,mini);
            maxi = max(i,maxi);
        }
    }
    for(int i = mini; i<=maxi;++i)
    {
        answer.push_back(arr[i]);
    }
    if(answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}