#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    for(auto & i : array)
    {
        if(i == n)
        {
            answer++;
        }
    }
    return answer;
}