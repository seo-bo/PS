#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<int,pii>mm = {{1,{0,0}},{2,{0,1}},{3,{0,2}},{4,{1,0}},{5,{1,1}},{6,{1,2}},{7,{2,0}},
                     {8,{2,1}},{9,{2,2}},{0,{3,1}}};
    pii l = make_pair(3,0);
    pii r = make_pair(3,2);
    for(auto & i : numbers)
    {
        if((i + 2) % 3 == 0)
        {
            answer += 'L';
            l = mm[i];
        }
        else if(i % 3 == 0 && i)
        {
             answer += 'R';
             r = mm[i];
        }
        else
        {
            auto [x,y] = mm[i];
            int a = abs(l.first - x) + abs(l.second - y);
            int b = abs(r.first - x) + abs(r.second - y);
            if(a > b)
            {
                r = make_pair(x,y);
                answer += 'R';
            }
            else if (a < b)
            {
                l = make_pair(x,y);
                answer += 'L';
            }
            else
            {
                if(hand == "left")
                {
                    l = make_pair(x,y);
                    answer += 'L';
                }
                else
                {
                    r = make_pair(x,y);
                    answer += 'R';
                }
            }
        }
    }
    return answer;
}