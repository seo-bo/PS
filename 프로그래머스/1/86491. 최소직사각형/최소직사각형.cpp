#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int aa = -1, bb = -1;
    for(auto & i : sizes)
    {
        if(i[0] > i[1])
        {
            swap(i[0],i[1]);
        }
        aa = max(aa,i[0]), bb = max(bb,i[1]);
    }
    return aa * bb;
}