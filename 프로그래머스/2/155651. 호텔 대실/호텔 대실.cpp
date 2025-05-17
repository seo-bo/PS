#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    auto cal = [&] (string str)
    {
      return (60*((str[0]-'0') * 10 + (str[1]-'0'))) + (str[3]-'0') * 10 + (str[4] - '0');  
    };
    vector<pii>v;
    for(auto & i :book_time)
    {
        v.push_back(make_pair(cal(i[0]),cal(i[1])));
    }
    sort(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto & [a,b] : v)
    {
        if(!pq.empty())
        {
            while(!pq.empty() && pq.top() <= a)
            {
                pq.pop();
            }
        }
        pq.push(b + 10);
        answer = max(answer, (int)pq.size());
    }
    return answer;
}