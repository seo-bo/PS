#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.rbegin(),score.rend());
    int maxi = k+1;
    for(int i =0, cnt = 0; i<score.size(); ++i, cnt = (cnt+1) % m)
    {
        maxi = min(maxi,score[i]);
        if(cnt == m-1)
        {
            answer += m * maxi;
            maxi = k+1;
        }
    }
    return answer;
}