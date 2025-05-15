#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int> pii;
typedef tuple<string,int,int> tp;
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pii>ok;
    vector<tp>v;
    auto cal = [&] (string time)
    {
        return 60 * ((time[0] -'0') * 10 + (time[1] -'0')) + (time[3] -'0') * 10 + (time[4] -'0');   
    };
    for(auto & i : plans)
    {
        v.push_back(make_tuple(i[0],cal(i[1]),stoi(i[2])));
    }
    sort(v.begin(), v.end(),[&] (const tp &a, const tp &b)
         {
             return get<1>(a) < get<1>(b);
         });
    int now = 0;
    for(auto & i : v)
    {
        auto [a,b,c] = i;
        int temp = b - now;
        while(!ok.empty() && temp)
        {
            int pivot = min(temp,ok.back().second);
            ok.back().second -= pivot;
            if(ok.back().second == 0)
            {
                answer.push_back(ok.back().first);
                ok.pop_back();
            }
            temp -= pivot;
        }
        ok.push_back(make_pair(a,c));
        now = b;
    }
    while(!ok.empty())
    {
        answer.push_back(ok.back().first);
        ok.pop_back();
    }
    return answer;
}