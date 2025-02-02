#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
int solution(string dartResult) {
    int answer = 0;
    vector<int>v(3);
    string temp = "";
    int idx = -1;
    for(auto & i : dartResult)
    {
        if('0' <= i && i <= '9')
        {
            temp += i;
        }
        else if(i == 'S' || i == 'D' || i == 'T')
        {
            idx++;
            ll sum = stoll(temp);
            if(i == 'D')
            {
                sum *= sum;
            }
            else if(i == 'T')
            {
                sum *= (sum * sum);
            }
            v[idx] = sum;
            temp = "";
        }
        else
        {
            if(i == '*')
            {
                v[idx] *= 2;
                if(idx-1 >=0)
                {
                    v[idx-1] *= 2;
                }
            }
            else
            {
                v[idx] *= -1;
            }
        }
    }
    for(auto & i : v)
    {
        answer += i;
    }
    return answer;
}