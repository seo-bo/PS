#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int solution(vector<int> array) {
    int answer = 0;
    vector<int>v(1500,0);
    for(auto & i : array)
    {
        v[i]++;
    }
    vector<pii>temp;
    for(int i =0; i<1111;++i)
    {
        if(v[i])
        {
            temp.push_back(make_pair(v[i],i));
        }
    }
    sort(temp.rbegin(),temp.rend());
    if(temp.size() == 1)
    {
        return temp[0].second;
    }
    else
    {
        return (temp[0].first == temp[1].first) ? -1 : temp[0].second;
    }
    return answer;
}