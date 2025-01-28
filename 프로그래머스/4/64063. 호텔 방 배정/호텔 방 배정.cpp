#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    unordered_map<ll,ll>parent;
    function<ll(ll)> find = [&] (ll root) -> ll
    {
        if(parent.find(root) == parent.end())
        {
            return root;
        }
        return parent[root] = find(parent[root]);
    };
    for(auto & i : room_number)
    {
        ll e = find(i);
        answer.push_back(e);
        parent[e] = e +1;
    }
    return answer;
}