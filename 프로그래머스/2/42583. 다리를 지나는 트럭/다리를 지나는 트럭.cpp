#include <string>
#include <vector>
#include <utility>
#include <deque>
using namespace std;
typedef pair<int,int> pii;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque<pii>dq;
    int idx = 0, n = truck_weights.size(), now = 0;
    while(idx < n || !dq.empty())
    {
        answer++;
        while(!dq.empty() && answer - dq.front().first == bridge_length)
        {
            now -= dq.front().second;
            dq.pop_front();
        }
        if(idx < n && truck_weights[idx] + now <= weight)
        {
            dq.push_back(make_pair(answer,truck_weights[idx++]));
            now += dq.back().second;
        }
    }
    return answer;
}