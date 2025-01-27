#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int a = 0, b = 1;
    for(auto & i : num_list)
    {
        a += i;
        b *= i;
    }
    if(b < a * a)
    {
        return 1;
    }
    return answer;
}