#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int>ok(2,0);
    char pivot = '?';
    for(auto & i : s)
    {
        if(pivot == '?')
        {
            pivot = i;
            ok[0]++;
            continue;
        }
        
        if(i != pivot)
        {
            ok[1]++;
        }
        else
        {
            ok[0]++;
        }
        if(ok[0] == ok[1])
        {
            answer++;
            pivot = '?';
            ok[0] = ok[1] = 0;
        }
    }
    return answer + (pivot != '?');
}