#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    sort(num_list.begin(),num_list.end());
    for(int i =5; i< (int)num_list.size();++i)
    {
        answer.push_back(num_list[i]);
    }
    return answer;
}