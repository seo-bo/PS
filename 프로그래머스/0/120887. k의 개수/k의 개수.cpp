#include <string>
#include <vector>

using namespace std;

int solution(int a, int j, int k) {
    int answer = 0;
    for(int i = a; i<=j;++i)
    {
        string str = to_string(i);
        for(auto & z : str)
        {
            int pivot= z - '0';
            if(pivot == k)
            {
                answer++;
            }
        }
    }
    return answer;
}