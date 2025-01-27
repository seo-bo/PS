#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    string str = to_string(num);
    for(int i =0; i<(int)str.size();++i)
    {
        if(str[i] -'0' == k)
        {
            return i +1;
        }
    }
    return answer;
}