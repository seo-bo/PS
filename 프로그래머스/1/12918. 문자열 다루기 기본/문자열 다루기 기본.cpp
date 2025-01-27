#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() == 4 || s.size() == 6)
    {
        for(auto & i : s)
        {
            if('0' <= i && i <='9')
            {
                continue;
            }
            return false;
        }
        return true;
    }
    return false;
}