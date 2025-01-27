#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    map<int,int>mm;
    for(auto & i :strArr)
    {
        answer = max(answer, ++mm[(int)i.size()]);
    }
    return answer;
}