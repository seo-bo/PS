#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(auto & i :array)
    {
        string str = to_string(i);
        for(auto & j : str)
        {
            int pivot= j -'0';
            if(pivot == 7)
            {
                answer++;
            }
        }
    }
    return answer;
}