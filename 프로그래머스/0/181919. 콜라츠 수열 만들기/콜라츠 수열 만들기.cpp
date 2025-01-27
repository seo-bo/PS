#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    while (n != 1)
    {
        answer.push_back(n);
        if(n % 2)
        {
            n = n * 3  +1;
        }
        else
        {
            n /= 2;
        }
    }
    answer.push_back(1);
    return answer;
}