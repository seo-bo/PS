#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    for(auto & i : scoville)
    {
        pq.push(i);
    }
    while(pq.size() >=2 && pq.top() < K)
    {
        ll a = pq.top();pq.pop();
        ll b = pq.top();pq.pop();
        pq.push(a + b * 2);
        answer++;
    }
    return (pq.top() < K) ? -1 : answer;
}