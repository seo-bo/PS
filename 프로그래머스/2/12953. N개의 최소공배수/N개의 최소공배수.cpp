#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    for(auto & i : arr)
    {
        answer = lcm(i,answer);
    }
    return answer;
}