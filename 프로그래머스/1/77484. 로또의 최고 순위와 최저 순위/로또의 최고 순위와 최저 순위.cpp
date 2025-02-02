#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> win_nums, vector<int> lottos) {  
    int pivot =0, blind = 0, len = lottos.size() + 1;
    set<int>s(lottos.begin(),lottos.end());
    for(auto & i : win_nums)
    {
        if(!i)
        {
            blind++;
            continue;
        }
        if(s.find(i) != s.end())
        {
            pivot++;
        }
    }
    vector<int> answer = {min(len-1,len - (pivot + blind)),min(len-1,len-pivot)};
    return answer;
}