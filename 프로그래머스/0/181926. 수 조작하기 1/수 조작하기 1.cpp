#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, string control) {
    int answer = n;
    for(auto & i :control)
    {
        if (i == 'w')
        {
          answer++;  
        }
        else if(i == 's')
        {
            answer--;
        }
        else if (i == 'd')
        {
            answer += 10;
        }
        else
        {
            answer -= 10;
        }
    }
    return answer;
}