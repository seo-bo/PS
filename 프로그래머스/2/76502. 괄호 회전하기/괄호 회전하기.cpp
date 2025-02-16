#include <string>
#include <vector>
#include <deque>
#include <map>
using namespace std;

bool check(deque<char>dq)
{
    map<char,char>mm = {{'[','?'},{'(','?'},{'{','?'},{']','['},{')','('},{'}','{'}};
    vector<char>s;
    for(auto & i : dq)
    {
        if(s.empty())
        {
            s.push_back(i);
            continue;
        }
        if(mm[i] == '?')
        {
            s.push_back(i);
        }
        else
        {
            if(s.back() != mm[i])
            {
                return false;
            }
            s.pop_back();
        }
    }
    return s.empty();
}

int solution(string s) {
    int answer = 0;
    deque<char>dq;
    int len = s.size();
    for(auto & i : s)
    {
        dq.push_back(i);
    }
    for(int i =0; i<len;++i)
    {
        if(check(dq))
        {
            answer++;
        }
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return answer;
}