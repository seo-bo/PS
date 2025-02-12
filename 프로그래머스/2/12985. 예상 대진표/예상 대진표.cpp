#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while((a+1) >> 1 != (b + 1) >> 1)
    {
        a = (a + 1) >> 1;
        b = (b + 1) >> 1;
        answer++;
    }
    return answer;
}