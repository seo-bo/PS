#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;

struct cmp
{
    bool operator()(const pair<int, int>& a, pair<int, int>& b)
    {
        return (a.first == b.first) ? a.second > b.second : a.first > b.first;
    }
};

int solution(vector<int> food_times, long long k)
{
    int idx = 1;
    priority_queue<pair<int,int>, vector<pair<int, int>>, cmp>pq;
    for (auto &i : food_times) 
    {
        pq.push(make_pair(i,idx++));
    }
    ll time = 0;
    while(!pq.empty())
    {
        ll dif = (pq.top().first - time) * pq.size();
        if (dif <= k)
        {
            k -= dif;
            time = pq.top().first;
            pq.pop();
        }
        else
        {
            vector<int>st;
            idx = k % pq.size(); // 사이클 X
            while(!pq.empty())
            {
                st.push_back(pq.top().second);
                pq.pop();
            }
            sort(st.begin(), st.end());
            return st[idx];
        }
    }
    return -1;
}