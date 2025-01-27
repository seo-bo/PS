#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    if(ineq == ">")
    {
        if(eq == "=")
        {
            return n >= m;
        }
        else
        {
            return n > m;
        }
    }
    else
    {
        if(eq == "=")
        {
            return n <= m;
        }
        else
        {
            return n < m;
        }
    }
    return answer;
}