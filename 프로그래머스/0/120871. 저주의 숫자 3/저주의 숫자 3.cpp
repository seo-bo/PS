#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int cnt = 0, cur = 1;
    while(1)
    {
        if(cur % 3 == 0 || to_string(cur).find('3') != string::npos)
        {
            cur++;
            continue;
        }
        cnt++;
        if(cnt == n)
        {
            return cur;
        }
        cur++;
    }
}