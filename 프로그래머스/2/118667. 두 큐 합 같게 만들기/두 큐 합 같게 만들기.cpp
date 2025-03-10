#include <string>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    deque<ll>dq1, dq2;
    ll s1 = 0, s2= 0 ;
    int alen = queue1.size(), blen = queue2.size();
    for(auto & i : queue1)
    {
        dq1.push_back(i);
        s1 += i;
    }
    for(auto & i : queue2)
    {
        dq2.push_back(i);
        s2 += i;
    }
    if((s1 + s2) % 2)
    {
        return -1;
    }
    ll ok = (s1 + s2) / 2;
    while(answer <= (alen+blen) * 4)
    {
        if(s1 == ok)
        {
            return answer;
        }
        if (s1 > ok)
        {
            ll temp = dq1.front();
            s1 -= temp;
            dq1.pop_front();
            dq2.push_back(temp);
        }
        else
        {
            ll temp = dq2.front();
            s1 += temp;
            dq2.pop_front();
            dq1.push_back(temp);
        }
        answer++;
    }
    return -1;
}