#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int len = prices.size();
    vector<int> answer(len,0), s;
    for(int i =0; i<len;++i)
    {
        while(!s.empty() && prices[s.back()] > prices[i])
        {
            answer[s.back()] = i - s.back();
            s.pop_back();
        }
        s.push_back(i);
    }
    while(!s.empty())
    {
        answer[s.back()] = len -s.back() - 1;
        s.pop_back();
    }
    return answer;
}