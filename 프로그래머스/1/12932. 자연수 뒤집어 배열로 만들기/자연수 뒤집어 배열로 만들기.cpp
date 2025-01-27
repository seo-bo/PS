#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);
    for(auto & i : str)
    {
        answer.push_back(i -'0');
    }
    reverse(answer.begin(),answer.end());
    return answer;
}