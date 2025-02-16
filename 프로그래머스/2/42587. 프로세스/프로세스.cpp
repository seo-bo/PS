#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>
using namespace std;
typedef pair<int,int> pii;

int solution(vector<int> priorities, int location) {
    int answer = 0, n = priorities.size();
    queue<int>q;
    map<int,int>mm;
    for(int i =0; i<n;++i)
    {
        mm[priorities[i]]++;
        q.push(i);
    }
    int cnt = 1;
    while(!q.empty())
    {
        int pivot = priorities[q.front()];
        auto it = prev(mm.end())->first;
        if(pivot == it)
        {
            if(location == q.front())
            {
                return cnt;
            }
            cnt++;
            q.pop();
            if(--mm[pivot] == 0)
            {
                mm.erase(pivot);
            }
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}