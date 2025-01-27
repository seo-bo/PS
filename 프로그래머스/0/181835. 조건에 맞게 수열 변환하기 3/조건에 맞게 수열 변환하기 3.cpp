#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    for(auto & i :arr)
    {
        if(k&1)
        {
            i *= k;
        }
        else
        {
            i += k;
        }
    }
    return arr;
}