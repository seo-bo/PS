#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(auto & i : s1)
    {
        for(auto & j : s2)
        {
            if(i == j)
            {
                answer++;
            }
        }
    }
    return answer;
}