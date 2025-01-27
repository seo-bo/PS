#include <string>
#include <vector>
using namespace std;
typedef long long ll;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(ll i =x,cnt =0;cnt <n;i += x,cnt++)
    {
        answer.push_back(i);
    }
    return answer;
}