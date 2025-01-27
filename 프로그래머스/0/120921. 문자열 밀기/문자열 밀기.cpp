#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(string A, string B) {
    int answer = -1, cnt = 1;
    if(A == B)
    {
        return 0;
    }
    deque<char>aa,bb;
    int len = A.size();
    for(auto & i : A)
    {
        aa.push_back(i);
    }
    for(auto & i : B)
    {
        bb.push_back(i);
    }
    for(int i =0; i<len;++i,++cnt)
    {
        aa.push_front(aa.back());
        aa.pop_back();
        if(aa == bb)
        {
            return cnt;
        }
    }
    return answer;
}