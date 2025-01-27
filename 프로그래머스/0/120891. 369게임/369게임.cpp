#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    string str = to_string(order);
        for(auto & j : str)
        {
            int p = j - '0';
            if(p > 0 && p % 3 == 0)
            {
                answer++;
            }
        }
    return answer;
}