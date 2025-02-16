#include <string>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    ll pivot = left / n, pos = left % n;
    pos++;
    for(int i = 0; i <= right - left;++i)
    {
        if(pivot >= pos)
        {
            answer.push_back(pivot + 1);
        }
        else
        {
            answer.push_back(pos);
        }
        pos++;
        if(pos == n + 1)
        {
            pos = 1;
            pivot++;
        }
    }
    return answer;
}