#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0, n = citations.size();
    sort(citations.begin(),citations.end());
    for(auto & i : citations)
    {
        auto it = lower_bound(citations.begin(),citations.end(),i) - citations.begin();
        int b = n - it;
        if(b <= i)
        {
           return b;
        }
    }
    return answer;
}