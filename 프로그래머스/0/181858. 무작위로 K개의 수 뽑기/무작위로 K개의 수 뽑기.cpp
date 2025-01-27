#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer(k,-1);
    set<int>s;
    int idx = 0;
    for(auto & i : arr)
    {
        if(idx == k)
        {
            break;
        }
        if(s.find(i) == s.end())
        {
            s.insert(i);
            answer[idx++] = i;
        }
    }
    return answer;
}