#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i =0; i<n;++i)
    {
        vector<int>temp(n);
        for(int j = n-1; j>=0;--j)
        {
            if(arr1[i] & (1<<j))
            {
                temp[j] |= 1;
            }
            if(arr2[i] & (1<<j))
            {
                temp[j] |= 1;
            }
        }
        string str;
        for(auto & j : temp)
        {
            str += ((j) ? "#" : " ");
        }
        reverse(str.begin(),str.end());
        answer.push_back(str);
    }
    return answer;
}