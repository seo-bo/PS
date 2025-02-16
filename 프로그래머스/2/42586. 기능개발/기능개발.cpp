#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = speeds.size();
    int cnt = 1, idx = 0;
    while(idx < n)
    {
        int pivot = 0;
        while(idx < n && progresses[idx] + speeds[idx] * cnt >= 100)
        {
            idx++;
            pivot++;
        }
        if(pivot)
        {
            answer.push_back(pivot);
        }
        cnt++;
    }
    return answer;
}