#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    for(auto & i : my_string)
    {
        for(int j= 0; j<n;++j)
        {
            answer += i;
        }
    }
    return answer;
}