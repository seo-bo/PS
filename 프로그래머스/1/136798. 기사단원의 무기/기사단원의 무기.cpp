#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int>factor(number+1, 1);
    for(int i =2;i<=number;++i)
    {
        for(int j =i; j<=number;j+=i)
        {
            factor[j]++;
        }
    }
    for(auto & i : factor)
    {
        int temp = i;
        if(temp > limit)
        {
            temp = power;
        }
        answer += temp;
    }
    return answer -1;
}