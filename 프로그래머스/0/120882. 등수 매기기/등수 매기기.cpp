#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> solution(vector<vector<int>> score) {
    vector<pii>v;
    int n = score.size();
    vector<int> answer(n,0);
    for(int i =0; i<(int)score.size();++i)
    {
        v.push_back(make_pair(score[i][0] + score[i][1],i));
    }
    sort(v.rbegin(),v.rend());
    int pre = INT_MAX, cnt = 0, temp = 1;
    for(auto & [_,a]:v)
    {
        if(pre != _)
        {
            cnt = temp;
            pre = _;
        }
        answer[a] = cnt;
        temp++;
    }
    return answer;
}