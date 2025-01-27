#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0, len = p.size();
    long long pivot = stoll(p);
    for(int i =0; i + len -1 < (int)t.size();++i)
    {
        if(stoll(t.substr(i,len)) <= pivot )
        {
            answer++;
        }
    }
    return answer;
}